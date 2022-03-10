#include "Observer.h"

void main()
{
	Commander commander;
	Marin marin[3];
	Medic medic[2];

	commander.SelecUnit(&marin[0]);
	commander.SelecUnit(&marin[1]);
	commander.SelecUnit(&marin[2]);

	commander.SelecUnit(&medic[0]);
	commander.SelecUnit(&medic[1]);

	commander.Move(10, 10);

	Unit* target = new Marin();

	commander.DeselectUnit(&medic[0]);
	commander.DeselectUnit(&medic[1]);

	commander.Attack(target);
	commander.Attack(target);
	commander.Attack(target);

	commander.DeselectUnit(&marin[0]);
	commander.DeselectUnit(&marin[1]);
	commander.DeselectUnit(&marin[2]);

	commander.SelecUnit(&medic[0]);
	commander.SelecUnit(&medic[1]);

	commander.Heal(target);

}