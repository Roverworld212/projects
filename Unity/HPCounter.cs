using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HPCounter : MonoBehaviour
{
    //Vars
    private int hitPoints = 100;//CurrentHP
    private int maxHP = 100;//Max HP allowed
    private int deathNum = 0;//Customize the HP required to die

    void Start()
    {
    }

    void WasHit()
    {//Call from a different C# script when hit and after dealing damage
        DeathCheck();
    }

    void DeathCheck()
    {
        if (hitPoints <= deathNum)
        {
            //DIE
        }
    }

    void TakeDamage(int dmg)
    {
        DeathCheck();
        if (hitPoints < dmg)
        {
            hitPoints = 0;
        }
        else
        {
            hitPoints = hitPoints - dmg;
        }
        DeathCheck();
    }

    void TakeHealth(int hp)
    {
        DeathCheck();
        int atc = hitPoints + hp;//This may be unnecessary to do
        if (atc > maxHP)
        {
            hitPoints = maxHP;
        }
        else
        {
            hitPoints = hitPoints + hp;
        }
    }

    void PrintOutHP()
    {
        Debug.Log(hitPoints);
    }
}
