#include<iostream>
using namespace std;

class Meal{
    protected:
        string mealType;
        int calories;
    public:
        Meal(){}
        Meal(string mealType, int calories): mealType(mealType), calories(calories){}
        void prepare(){
            cout<<"Meal is being prepared"<<endl;
        }
        int calculateCaloriesCount(){
            return calories;
        }
        void addCalories(int cal){
            calories+=cal;
        }

};
class Breakfast:public Meal{
    protected:
        bool hasCoffee;
    public:
        Breakfast(){}
        Breakfast(string mealType, int calories, bool hasCoffee): Meal(mealType, calories), hasCoffee(hasCoffee){}
        void prepareBreakfast(){
            cout<<"Breakfast is being prepared"<<endl;
        }
};
class Dinner:public Meal{
    protected:
        bool isSpecialDinner;
    public:
        Dinner(){}
        Dinner(string mealType, int calories, bool isSD): Meal(mealType, calories), isSpecialDinner(isSD){}
        void prepareDinner(){
            cout<<"Dinner is being prepared"<<endl;
        }
        void prepareSpecialDinner(){
            if (isSpecialDinner)
            {
                cout<<"Special dinner is being prepared using special ingredients"<<endl;
                addCalories(500);
            }
            else{
                cout<<"No special ingredients available"<<endl;
            }
            
        }
};
class Cereal:public Breakfast{
    protected:
        string cerealType,milkType;
    public:
        Cereal(){}
        Cereal(string mealType, int calories, bool hasCoffee, string cerealType, string milkType): Breakfast(mealType, calories, hasCoffee), cerealType(cerealType), milkType(milkType){}
        void addMilk(){
            cout<<"Milk is being added to cereal"<<endl;
        }
};
class Omlette:public Breakfast{
    protected:
        string eggType, fillingType;
    public:
        Omlette(){}
        Omlette(string mealType, int calories, bool hasCoffee, string eggType, string fillingType): Breakfast(mealType, calories, hasCoffee), eggType(eggType),fillingType(fillingType){}
        void cookOmelette(){
            cout<<"Omelette is being cooked"<<endl;
        }
};
class MeatDish: public Dinner{
    protected:
        string meatType, sideDish;
    public:
        MeatDish(){}
        MeatDish(string mealType, int calories, bool isSD, string meatType, string sideDish): Dinner(mealType, calories, isSD), meatType(meatType), sideDish(sideDish){}
        void cookMeatDish(){
            cout<<"Meat is being cooked"<<endl;
        }
};
class VegetarianDish:public Dinner{
    protected:
        string mainIngredient, additionalIngredient;
    public:
        VegetarianDish(){}
        VegetarianDish(string mealType, int calories, bool isSD, string mainIng, string addIng): Dinner(mealType, calories, isSD), mainIngredient(mainIng), additionalIngredient(addIng){}
        void prepareVegetarianDish(){
            cout<<"Vegetarian dish is being cooked"<<endl;
        }
};
int main(){
    Cereal b1("Breakfast", 200, true, "Cornflakes", "Full Cream");
    Omlette b2("Breakfast", 300, true, "Hen", "Cheese");
    MeatDish d1("Dinner", 500, true, "Beef", "Rice");
    VegetarianDish d2("Dinner", 400, false, "Lentils", "Spinach");
    b1.prepare();
    b1.addMilk();
    b2.prepare();
    b2.cookOmelette();
    d1.prepare();
    d1.cookMeatDish();
    d1.prepareSpecialDinner();
    d2.prepare();
    d2.prepareVegetarianDish();
    d2.prepareSpecialDinner();
    cout<<"Total calories in breakfast: "<<b1.calculateCaloriesCount()<<endl;
    cout<<"Total calories in breakfast 2: "<<b2.calculateCaloriesCount()<<endl;
    cout<<"Total calories in dinner: "<<d1.calculateCaloriesCount()<<endl;
    cout<<"Total calories in dinner 2: "<<d2.calculateCaloriesCount()<<endl;
    return 0;
}