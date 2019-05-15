/*
Insert bullet counter for unity
Maybe when i get home... maybe
I a making this mainly to keep myself coding even when at school in classes that to me are pointless. I plan to make more scripts
for anyone to use and modify. If you have any suggestion on improving this (there is surely something better than this) please
share it with me!
*/
//Insert using and include stuff here
public class BC : Monobehavior {
  //Vars
  int bic = 30;//Bullets in clip
  int mbic = 30;//Max bullets to be loaded
  int bis = 200;//Bullets in storage
  int mbis = 200;//Max Bullets to be stored
  bool burstOn = false;//If player is using bust
  
void start(){
}

void Update() {//This update func may be a problem later on :/ I will test and fix it accordingly
if(/*Mouse1 clicked*/){//This is for a weapon that needs to be constantly clicked! Modification of this if would mean modification of the other code
  if(burstOn = true){
    if(bic <  3){
      bic = 0;
    }
    else{
      bic = bic - 3; 
  }
  else{
    --bic;
  }
}
}
void reload(){
  if(bis < mbic){
    bic = bis;
    bis = 0;
  }
  else{
    bis = bis - mbic;
  }
}
}
