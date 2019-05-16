//blah blah blah unity using tags go here
//My spaces may cause the code to fail btw
//My spacebar is broken

public class BC : Monobehavior {
  //Vars
  private int hitPoints = 100;//CurrentHP
  private int maxHP = 100;//Max HP allowed
  private deathNum = 0;//Customize the death limit
  
  void Start(){
  }

  void Update(){
    deathCheck();
  }
  
  void deathCheck(){
    if(hitPoints <= deathNum){
      //DIE
    }
  }

  void takeDamage(int dmg){
    deathCheck();
    if(hitPoints < dmg){
      hitPoints = 0;
    }
    else{
      hitPoints = hitPoints - dmg
    }
    deathCheck();
  }
  
  void takeHealth(int hp){
    deathCheck();
    int atc = hitPoints + hp;//This may be unnecessary to do
    if(atc > maxHP){
      hitPoints = maxHP;
    }
    else{
      hitPoints = hitPoints + hp;
    }
  }
  
  void printOutHP(){
    Debug.Log(hitPoints);
  }
  
}
