#include <iostream>
using namespace std;

class ScoreTest{
    int totalScores;
    int *testScores;
    public:
    ScoreTest(int n){
        if(n>0)
     testScores = new int[n];
     totalScores+=n;
    }
     ScoreTest(ScoreTest &o){
        testScores = new int[o.totalScores-1];
        totalScores = o.totalScores;
        for(int i=0;i<totalScores;i++){
            testScores[i] = o.testScores[i];
        }    
    }
    float avg(){
        int sum=0;
        for(int i=0;i<totalScores;i++){
            sum+=testScores[i];
        }
        float avgS = (float) sum/totalScores;
        return avgS;
    }
    int* getTestScores(){
        return testScores;
    }
    int getNum(){
        return totalScores;
    }
    void mutator(){
        cout<<"\t\tScores<\n\n";
        for(int i=0;i<totalScores;i++)
            cout<<"Score\t\t"<<testScores[i];
    }

};

int main(){
    ScoreTest a(5);
    cout<<"Average: "<<a.avg();
    a.mutator();
    ScoreTest b(a);
    cout<<"Average: "<<a.avg();
    a.mutator();

}