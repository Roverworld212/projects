using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//There are always some sort of errors in my code
//Typing this on a restricted school computer doesn't let me test it
public class DistanceWalked : MonoBehaviour
{
float timer = 0f;
float distanceWalked = 0f;

void Update(){
while(/*W is held*/){//Get the seconds W is held
timer += Time.deltaTime;
int seconds = timer % 60;
}
Calculate(seconds);//Calculate the distance walked
}

void Calculate(int s){
while(s >= 60){//for every 60 seconds add 0.05 to the distance
s = s - 60;//Subtract 60
distanceWalked = distanceWalked + 0.05;//Add to the distance  
}
}
}
