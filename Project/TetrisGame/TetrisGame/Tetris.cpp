#include <Turboc.h>
#include <algorithm>
#include <string.h> 

#define AREASIZE_W 10
#define AREASIZE_H 20

//방향키의 아스키 코드값
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_SPACE 32

const char* printChar[3] = { "□", " '", "■" };
enum ePrintChar
{
	OUTLINE = 0,
	SPACE,
	BLOCK
};
short int screen[AREASIZE_H + 2][AREASIZE_W + 2];
bool stackedBlock[AREASIZE_H][AREASIZE_W] = { false, };
const char* testCommand = "대기";
struct Position
{
	int x;
	int y;

	Position(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};
enum eTetromino
{
	I = 0,
	O,
	Z,
	S,
	J,
	L,
	T
};
struct Block
{
	eTetromino type;
	short int rotate;
	Position pos = Position(5, 2);
};
//			   type rotate pos
Position tetromino[7][4][4] =
{
	//I
	{
		{Position(0,-1),Position(0,0),Position(0,1),Position(0,2)},	//정방향
		{Position(-1,0),Position(0,0),Position(1,0),Position(2,0)},		//90도 회전
		{Position(0,-2),Position(0,-1),Position(0,0),Position(0,1)},	//270도 회전
		{Position(-1,0),Position(0,0),Position(1,0),Position(2,0)}
	},
	//O
	{
		{Position(-1,-1),Position(-1,0),Position(0,-1),Position(0,0)},
		{Position(-1,-1),Position(-1,0),Position(0,-1),Position(0,0)},
		{Position(-1,-1),Position(-1,0),Position(0,-1),Position(0,0)},
		{Position(-1,-1),Position(-1,0),Position(0,-1),Position(0,0)}
	},
	//Z
	{
		{Position(-1,-1),Position(0,-1),Position(0,0),Position(1,0)},
		{Position(0,0),Position(0,1),Position(1,-1),Position(1,0)},
		{Position(-1,-1),Position(0,-1),Position(0,0),Position(1,0)},
		{Position(0,0),Position(0,1),Position(1,-1),Position(1,0)}
	},
	//S
	{
		{Position(-1,0),Position(0,-1),Position(0,0),Position(1,-1)},
		{Position(-1,-1),Position(-1,0),Position(0,0),Position(0,1)},
		{Position(-1,0),Position(0,-1),Position(0,0),Position(1,-1)},
		{Position(-1,-1),Position(-1,0),Position(0,0),Position(0,1)}
	},
	//J
	{
		{Position(-1,1),Position(0,-1),Position(0,0),Position(0,1)},
		{Position(-1,-1),Position(-1,0),Position(0,0),Position(1,0)},
		{Position(0,-1),Position(0,0),Position(0,1),Position(1,-1)},
		{Position(-1,0),Position(0,0),Position(1,0),Position(1,1)}
	},
	//L
	{
		{Position(0,-1),Position(0,0),Position(0,1),Position(1,1)},
		{Position(-1,0),Position(-1,1),Position(0,0),Position(1,0)},
		{Position(-1,-1),Position(0,-1),Position(0,0),Position(0,1)},
		{Position(-1,0),Position(0,0),Position(1,-1),Position(1,0)}
	},
	//T
	{
		{Position(-1,0),Position(0,-1),Position(0,0),Position(1,0)},
		{Position(0,-1),Position(0,0),Position(0,1),Position(1,0)},
		{Position(-1,0),Position(0,0),Position(0,1),Position(1,0)},
		{Position(-1,0),Position(0,-1),Position(0,0),Position(0,1)}
	},
};
Block currentBlk;
bool isBlockSpawned = false;
enum eArround
{
	LEFT = 0,
	RIGHT,
	TOP,
	BOTTOM
};

clock_t oldTime, currentTime;
bool isGameOver = false;

int score;

//유니티 스크립트 생명주기 참고
void Init();
void Update();
void Render();
void Release();

void PrintScreen();	//화면 그리기 (정해진 시간마다 호출)
void InputManager(); // 키 입력 감지, 동작 관리

void PrintCurrentBlk();	//현재 블록 그리기
void RemoveCurrentBlk();	//현재 블록 지우기 (위치, 방향 갱신시 블록을 다시 그려주기전에 지우는 작업)
void RandomBlock();	//블록 랜덤 생성
void RotateBlock();	//블록 돌리기
bool MoveBlock(eArround command);	//command에 따라 블록 위치 변경
bool CheckAround(eArround command); //command에 따라 해당 방향에 공간이 있는지 체크
void StackBlock();	//현재 블록이 바닥에 닿았을때 쌓아주기
void CheckLine();	//쌓인 블록들 중 줄 완성된게 있는지 체크 후 삭제, 나머지 블록 내리기
bool Timer(); //자동 내리기를 위한 타이머

void Init()	//데이터 초기화
{
	//커서 설정
	setcursortype(NOCURSOR);

	//화면에 출력시켜줄 배열 초기 설정
	for (int i = 0; i < AREASIZE_H + 2; i++)
	{
		for (int j = 0; j < AREASIZE_W + 2; j++)
		{
			if (i % (AREASIZE_H + 1) == 0 || j % (AREASIZE_W + 1) == 0)
				screen[i][j] = OUTLINE;
			else
			{
				screen[i][j] = stackedBlock[i - 1][j - 1] ? BLOCK : SPACE;
			}
		}
	}

	//자동 내리기를 위한 time 변수
	oldTime = clock();

	score = 0;
}
void Update()	//게임 내 데이터 갱신
{
	//키조작
	InputManager();
	//블럭 
	RandomBlock();
}
void Render()	//화면 그리기
{
	PrintScreen();
}
void Release()
{

}

int main(void)
{
	Init();

	while (!isGameOver)
	{
		Update();
		Render();
	}
	gotoxy(0, 23);
	Release();
	return 0;
}

void PrintScreen()
{
	//clrscr();
	for (int y = 0; y < AREASIZE_H + 2; y++)
	{
		for (int x = 0; x < AREASIZE_W + 2; x++)
		{
			gotoxy(x * 2, y);
			puts(printChar[screen[y][x]]);
		}
	}
	//스코어
	gotoxy(27, 2);
	puts("SCORE : ");
	gotoxy(35, 2);
	printf("%d", score);

	//테스트 코드
	gotoxy(30, 10);
	puts(testCommand);
}
void InputManager()
{
	int inputKey;
	if (_kbhit())
	{
		inputKey = _getch();
		//printf("%d\n", (int)inputKey);

		switch (inputKey)
		{
		case KEY_LEFT:
			testCommand = "LEFT  ";
			MoveBlock(LEFT);
			break;
		case KEY_RIGHT:
			testCommand = "RIGHT";
			MoveBlock(RIGHT);
			break;
		case KEY_UP:
			testCommand = "UP   ";
			RotateBlock();
			//블럭 돌리기
			break;
		case KEY_DOWN:
			if (!MoveBlock(BOTTOM))
				StackBlock();
			testCommand = "DOWN ";
			break;
		case KEY_SPACE:
			testCommand = "SPACE";
			//맨 밑으로 내리기
			for (int i = 0; i < AREASIZE_H; i++)
			{
				if (!MoveBlock(BOTTOM))
					break;
			}
			StackBlock();
			break;
		default:
			testCommand = "대기   ";
			break;
		}
	}
	else
	{
		//블록 자동으로 내리기
		if (Timer())
		{
			if (!MoveBlock(BOTTOM))
				StackBlock();
		}
	}
}

void PrintCurrentBlk()
{
	if (isBlockSpawned)
	{
		eTetromino type = currentBlk.type;
		int rotate = currentBlk.rotate;

		//블럭 그리기
		for (int i = 0; i < 4; i++)
		{
			int x, y;
			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;
			if (screen[y][x] != OUTLINE)
				screen[y][x] = BLOCK;
		}
	}
}
void RemoveCurrentBlk()
{
	if (isBlockSpawned)
	{
		int x, y;
		int type = currentBlk.type;
		int rotate = currentBlk.rotate;

		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;

			bool chk = y % (AREASIZE_H + 1) == 0 || x % (AREASIZE_W + 1) == 0;
			screen[y][x] = chk? OUTLINE : SPACE;
		}
	}
}
void PrintStackedBlock()
{
	int cnt = 0;
	for (int y = AREASIZE_H - 1; y >= 0; y--)
	{
		for (int x = AREASIZE_W - 1; x >= 0; x--)
		{
			if (stackedBlock[y][x])
			{
				screen[y + 1][x + 1] = BLOCK;
				cnt++;
			}
		}
		if (cnt <= 0)
			break;
		else
			cnt = 0;
	}
}
void RandomBlock()
{
	if (!isBlockSpawned)
	{
		isBlockSpawned = true;
		randomize();
		int bolckType = random(6);
		currentBlk.pos = Position(5, 2);
		currentBlk.type = (eTetromino)bolckType;
		currentBlk.rotate = 0;
		PrintCurrentBlk();
	}
}
void RotateBlock()
{
	if (isBlockSpawned)
	{
		RemoveCurrentBlk();

		int type = currentBlk.type;
		int rotate = (currentBlk.rotate + 1) % 4;
		currentBlk.rotate = rotate;

		//바뀐 방향의 블록이 외곽선, 블록 겹치지 않는지 검사 후 위치 옮겨주기
		for (int i = 0; i < 4; i++)
		{
			int x, y;

			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;

			if (screen[y][x] != SPACE)
			{
				//
				if (CheckAround(LEFT))
					MoveBlock(LEFT);
				else if (CheckAround(RIGHT))
					MoveBlock(RIGHT);
				if (CheckAround(BOTTOM))
					MoveBlock(BOTTOM);
			}
		}
		PrintCurrentBlk();
	}
}
bool MoveBlock(eArround command)
{
	if (isBlockSpawned)
	{
		int moveX = 0, moveY = 0;
		switch (command)
		{
		case LEFT:
			moveX = -1;
			break;
		case RIGHT:
			moveX = 1;
			break;
		case TOP:
			moveY = -1;
			break;
		case BOTTOM:
			moveY = 1;
			break;
		default:
			break;
		}
		RemoveCurrentBlk();
		if (CheckAround(command))
		{
			RemoveCurrentBlk();

			int goalX = currentBlk.pos.x + moveX;
			int goalY = currentBlk.pos.y + moveY;

			currentBlk.pos = Position(goalX, goalY);

			PrintCurrentBlk();
			return true;
		}
		else
		{
			PrintCurrentBlk();
			return false;
		}
	}
}
bool CheckAround(eArround command)
{
	int type = currentBlk.type;
	int rotate = currentBlk.rotate;
	int x, y;
	bool check = true;

	switch (command)
	{
	case LEFT:
		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x - 1;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;
			check &= screen[y][x] == SPACE;
		}
		break;
	case RIGHT:
		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x + 1;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;
			check &= screen[y][x] == SPACE;
		}
		break;
	case TOP:
		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y - 1;
			check &= screen[y][x] == SPACE;
		}
		break;
	case BOTTOM:
		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y + 1;
			check &= screen[y][x] == SPACE;
		}
		break;
	default:
		break;
	}
	return check;
}
void StackBlock()
{
	if (isBlockSpawned)
	{
		RemoveCurrentBlk();
		if (!CheckAround(TOP))
			isGameOver = true;

		int x, y;
		int type = currentBlk.type;
		int rotate = currentBlk.rotate;

		for (int i = 0; i < 4; i++)
		{
			x = currentBlk.pos.x + tetromino[type][rotate][i].x;
			y = currentBlk.pos.y + tetromino[type][rotate][i].y;
			//screen에 맞는 좌표

			stackedBlock[y - 1][x - 1] = true;
			screen[y][x] = BLOCK;
		}
		isBlockSpawned = false;
		CheckLine();
	}
}
void CheckLine()
{
	//전체 줄검사
	bool isFull[20] = { false, };
	int cntFull = 0;
	for (int chkLineY = AREASIZE_H - 1; chkLineY >= 0; chkLineY--)
	{
		int cntPixel = 0;
		//chkLineY 줄 full인지 검사
		for (int chkLineX = AREASIZE_W - 1; chkLineX >= 0; chkLineX--)
			cntPixel += stackedBlock[chkLineY][chkLineX] ? 1 : 0;
		if (cntPixel >= 10)
		{
			isFull[chkLineY] = true;
			cntFull++;
		}
		else if (cntPixel <= 0)
			break;
	}
	score += (cntFull * 1000) * (1 + (0.1 * (cntFull - 1)));
	//전체 줄 돌면서 삭제
	for (int chkLineY = AREASIZE_H - 1; chkLineY >= 0; chkLineY--)
	{
		if (isFull[chkLineY])
			for (int chkLineX = AREASIZE_W - 1; chkLineX >= 0; chkLineX--)
			{
				stackedBlock[chkLineY][chkLineX] = false;
				screen[chkLineY + 1][chkLineX + 1] = SPACE;
			}

	}
	//빈 줄 내리기
	for (int p = AREASIZE_H - 1; p >= 0; p--)
	{
		if (isFull[p])
			continue;
		else
		{
			for (int t = AREASIZE_H - 1; t >= 0; t--)
			{
				if (isFull[t])
				{
					for (int chkLineX = AREASIZE_W - 1; chkLineX >= 0; chkLineX--)
					{
						stackedBlock[t][chkLineX] = stackedBlock[p][chkLineX];
						stackedBlock[p][chkLineX] = false;

						screen[t + 1][chkLineX + 1] = stackedBlock[t][chkLineX] ? BLOCK : SPACE;
						screen[p + 1][chkLineX + 1] = SPACE;
					}
					isFull[p] = true;
					isFull[t] = false;
					break;
				}
			}
		}
	}
}
bool Timer()
{
	currentTime = clock();
	if (currentTime - oldTime > 1000)
	{
		oldTime = clock();
		return true;
	}
	else
		return false;
}