using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CoroutineCount : MonoBehaviour
{
    bool m_isCount;
    IEnumerator ProcessCount()
    {
        m_isCount = true;
        while (m_isCount)
        {
            yield return new WaitForSeconds(Time.deltaTime);
            m_nCoroutineCount++;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(ProcessCount());
    }

    int m_nUpdateCount;
    int m_nCoroutineCount;

    // Update is called once per frame
    void Update()
    {
        m_nUpdateCount++;
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 40), 
            "Update:" + m_nUpdateCount + "\nCoroutine:" + m_nCoroutineCount);
    }

    private void OnDestroy()
    {
        m_isCount = false;
    }
}
