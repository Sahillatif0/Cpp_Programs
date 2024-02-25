#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Pet{
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string *specialSkills;
    int skillsCount;

public:
    string name;
    Pet(){
        name = "Tom";
        healthStatus = "Healthy";
        hungerLevel = 1;
        happinessLevel = 8;
        skillsCount = 0;
    }
    Pet(string n, string hS, int hL, int hapLev):name(n),healthStatus(hS), hungerLevel(hL), happinessLevel(hapLev), skillsCount(0){}
    void updateHealthStatus(string hS){healthStatus = hS;}
    string getHealthStatus() const {return healthStatus;}
    void setHungerLevel(int hL){hungerLevel = hL;}
    int getHungerLevel() const {return hungerLevel;}
    void setHappinessLevel(int hapLev){happinessLevel = hapLev;}
    int getHappinessLevel() const {return happinessLevel;}
    void updateHungerLvl(int hL){
        if(hungerLevel>0) hungerLevel+=hL;
        if(hungerLevel>0) happinessLevel-=(hungerLevel/3);
        }
    void updateHappLvl(int hapLev){if(happinessLevel<10) happinessLevel+=hapLev;}
    void addSKill(string skill){
        string *temp = new string[skillsCount+1];
        for(int i = 0; i < skillsCount; i++)
            temp[i] = specialSkills[i];
        temp[skillsCount++] = skill;
        specialSkills = temp;
    }
    void displayPetDetails(){
        cout << "Name: " << name << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Skills: ";
        for(int i = 0; i < skillsCount; i++){
            cout << specialSkills[i] << ", ";
        }
        cout << endl;
    }


    
};

class Adopter{
    string adopMobNum;
    Pet *adoptedPetRecords;
    int petCount;
    public:
    string adopterName;
    Adopter(string aN, string aMN):adopterName(aN), adopMobNum(aMN), petCount(0){}
    Adopter(){}
    int getPetCount() const {return petCount;}
    void adoptPet(Pet p){
        adoptedPetRecords = new Pet[petCount+1];
        adoptedPetRecords[petCount++] = p;
    }
    void displayAdopterDetails(){
        cout << "Adopter Name: " << adopterName << endl;
        cout << "Adopter Mobile Number: " << adopMobNum << endl;
        cout << "Adopted Pets: " << endl;
        for(int i = 0; i < petCount; i++){
            cout << "-------------------------\n"<<i+1<<"."<<endl;
            adoptedPetRecords[i].displayPetDetails();
        }
    }
    bool comparePets(Pet p1, Pet p2){
        if(p1.getHealthStatus() == p2.getHealthStatus() && p1.getHungerLevel() == p2.getHungerLevel() && p1.getHappinessLevel() == p2.getHappinessLevel())
            return true;
        return false;
    }
    Pet getAdoptedPet(int ind){
        return adoptedPetRecords[ind];
    }
    void returnPet(Pet p){
        for(int i = 0; i < petCount; i++){
            if(comparePets(adoptedPetRecords[i], p)){
                adoptedPetRecords[i] = adoptedPetRecords[petCount-1];
                petCount--;
                break;
            }
        }
        adoptedPetRecords = new Pet[petCount];

    }
    void feed(int ind){
        adoptedPetRecords[ind].updateHungerLvl(-1);
        adoptedPetRecords[ind].updateHappLvl(1);
        cout<<endl<<adoptedPetRecords[ind].name<<" Fed Successfully\n\n";
        adoptedPetRecords[ind].displayPetDetails();
        
    }
    void playWithPet(int ind){
        adoptedPetRecords[ind].updateHungerLvl(1);
        adoptedPetRecords[ind].updateHappLvl(2);
        cout<<endl<<adoptedPetRecords[ind].name<<" played successfully, Pet is happy now\n\n";
        adoptedPetRecords[ind].displayPetDetails();
    }
    void trainPet(int ind){
        adoptedPetRecords[ind].updateHungerLvl(2);
        adoptedPetRecords[ind].updateHappLvl(3);
        cout<<endl<<adoptedPetRecords[ind].name<<" has completed todays Training\n\n";
        adoptedPetRecords[ind].displayPetDetails();
    }
    ~Adopter() {
    delete[] adoptedPetRecords;
    }
};
void existingAdopter(Adopter *adopters, int adopterCount, Pet *p, int &petCount){
    if(adopterCount == 0){
        cout << "No Adopters Available\n";
        return;
    }
    for(int i = 0; i < adopterCount; i++){
        cout << i+1 << ". " << adopters[i].adopterName << endl;
    }
    int adpN,opt,petN;
    cout<<"Enter your choice: ";
    cin>>adpN;
    adpN--;
    while(1){
    cout << "1. Adopt Pet\n2. Return Pet\n3. Feed Pet\n4. Play with Pet\n5. Train Pet\n6. Display Adopter Details\n7. Exit\nEnter your choice: ";
    cin >> opt;
    switch(opt){
        case 1:
            for(int i = 0; i < petCount; i++){
                cout << i+1 << ". "<<endl;
                p[i].displayPetDetails();
                cout<<endl;
            }
            do{
            cout<<"Enter Pet Number to adopt: ";
            cin>>petN;
            petN--;
            if(petN >= petCount){
                cout<<"Invalid Pet Number\n";
            }
            }while(petN >= petCount || petN<0);
            adopters[adpN].adoptPet(p[petN]);
            cout<<"Congratulations! You have adopted "<<p[petN].name<<endl;
            p[petN] = p[petCount-1];
            petCount--;
            break;
        case 2:
            adopters[adpN].displayAdopterDetails();
            if(adopters[adpN].getPetCount() == 0){
                cout<<"No Pets to return\n";
                break;
            }
            do{
            cout<<"Enter Pet Number to return: ";
            cin>>petN;
            petN--;
            if(petN >= adopters[adpN].getPetCount()){
                cout<<"Invalid Pet Number\n";
            }
            }while(petN >= adopters[adpN].getPetCount() || petN<0);
            adopters[adpN].returnPet(adopters[adpN].getAdoptedPet(petN));
            cout<<"You have returned Pet"<<endl;
            break;
        case 3:
            adopters[adpN].displayAdopterDetails();
            if(adopters[adpN].getPetCount() == 0){
                cout<<"No Pets to feed\n";
                break;
            }
            do{
            cout<<"Enter Pet Number to feed: ";
            cin>>petN;
            petN--;
            if(petN >= adopters[adpN].getPetCount()){
                cout<<"Invalid Pet Number\n";
            }
            }while(petN >= adopters[adpN].getPetCount() || petN<0);
            adopters[adpN].feed(petN);
            break;
        case 4:
            adopters[adpN].displayAdopterDetails();
            if(adopters[adpN].getPetCount() == 0){
                cout<<"No Pets to play\n";
                break;
            }
            do{
            cout<<"Enter Pet Number to Play: ";
            cin>>petN;
            petN--;
            if(petN >= adopters[adpN].getPetCount()){
                cout<<"Invalid Pet Number\n";
            }
            }while(petN >= adopters[adpN].getPetCount() || petN<0);
            adopters[adpN].playWithPet(petN);
            break;
        case 5:
            adopters[adpN].displayAdopterDetails();
            if(adopters[adpN].getPetCount() == 0){
                cout<<"No Pets to train\n";
                break;
            }
            do{
            cout<<"Enter Pet Number to Train: ";
            cin>>petN;
            petN--;
            if(petN >= adopters[adpN].getPetCount()){
                cout<<"Invalid Pet Number\n";
            }
            }while(petN >= adopters[adpN].getPetCount() || petN<0);
            adopters[adpN].trainPet(petN);
            break;
        case 6:
            adopters[adpN].displayAdopterDetails();
            break;
        case 7:
            return;
        default:
            cout << "Invalid Option\n";
    }
    }
}
void addnewAdopter(Adopter *&adopters, int &adopterCount){
    string name, mobNum;
    cout << "Enter Adopter Name: ";
    getline(cin, name);
    cout << "Enter Adopter Mobile Number: ";
    cin >> mobNum;
    Adopter newAdopter(name, mobNum);
    Adopter *newadopters = new Adopter[adopterCount + 1];
    for(int i = 0; i < adopterCount; i++)
        newadopters[i] = adopters[i];
    newadopters[adopterCount++] = newAdopter;
    delete [] adopters;
    adopters = newadopters;
    cout<<"\nAdopter Added Successfully\n\n";
}
void petsAvailable(Pet *p, int petCount){
    for(int i = 0; i < petCount; i++){
        cout << i+1 << ". "<<endl;
        p[i].displayPetDetails();
        cout<<endl;
    }
}
int main() {
    int opt;
    srand(time(0));
    Adopter *adopters = new Adopter[1];
    int adoptedPets[20] = {0};
    string petNames[20] = {"Bella", "Lucy", "Max", "Lily", "Charlie", "Daisy", "Buddy", "Sadie", "Rocky", "Molly", 
                           "Jack", "Lola", "Toby", "Chloe", "Cody", "Bailey", "Buster", "Sophie", "Bear", "Maggie"};
    string petHealthStatus[3] = {"Healthy", "Sick", "Injured"};
    Pet *pets = new Pet[20];
    for(int i = 0; i < 20; i++) {
        pets[i] = Pet(petNames[i], petHealthStatus[i%3], rand()%10, rand()%10);
    }
    int petCount = 20, adopterCount = 0;
    while(1){
    cout<<"1. Add New Adopter\n2. Existing Adopter\n3. Pets Available for Adoption\n4. Exit\nEnter your choice: ";
    cin>>opt;
    cin.ignore();
    switch(opt){
        case 1:
            addnewAdopter(adopters, adopterCount);
            existingAdopter(adopters, adopterCount,pets,petCount);
            break;
        case 2:
            existingAdopter(adopters, adopterCount,pets,petCount);
            break;
        case 3:
            petsAvailable(pets, petCount);
            break;
        case 4:
            return 0;
        default:
            cout<<"Invalid Option\n";
    }
    }
    return 0;
}
