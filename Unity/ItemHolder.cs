using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//Idk even know what this script is supposed to be, but here it is anyways
public class ItemHolder : MonoBehaviour
{
//Vars
private int oco[10];//Objects currently owned
//This should be static so others can access it, but for now it  will stay like this
void ChangeItem(int an,int wta){//Change num in array from other scripts
if(wta <= 9){//Make sure num is a valid number in the array
if(wta >= 0){
oco[wta] = an;
}
else{
Debug.Log(“Failed to change”);
}
}
else{
Debug.Log(“Failed to change”);
}
}
}
