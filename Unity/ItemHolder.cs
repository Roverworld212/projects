using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemHolder : MonoBehaviour
{
//Vars
private int oco[10];//Objects currently owned

void AddItem(int an,int wta){
if(wta <= 9){
oco[wta] = an;
}
else{
Debug.Log(“Failed to add”);
}
}

void RemoveItem(int wtr, int rn){
if(wtr <= 9){

}
else{
Debug.Log("Failed to remove");
}
}
}
