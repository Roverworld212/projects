using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletCounter : MonoBehaviour
{
    //Vars
    int bic = 30;//Bullets in clip
    int mbic = 30;//Max bullets to be loaded
    int bis = 200;//Bullets in storage
    int mbis = 200;//Max Bullets to be stored
    bool burstOn = false;//If player is using bust

    void Start()
    {
    }

    void Update()
    {//This update func may be a problem later on :/ I will test and fix it accordingly
        if (Input.GetMouseButtonUp(0))
        {//This is for a weapon that needs to be constantly clicked! Modification of this if would mean modification of the other code
            if (burstOn == true)
            {
                if (bic < 3)
                {
                    bic = 0;
                }
                else
                {
                    bic = bic - 3;
                }
            }
            else
            {
                --bic;
            }
        }
        void Reload()
        {
            if (bis < mbic)
            {
                bic = bis;
                bis = 0;
            }
            else
            {
                bis = bis - mbic;
            }
        }
    }
    }
