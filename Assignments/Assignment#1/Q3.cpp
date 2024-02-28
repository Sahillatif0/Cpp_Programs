#include <iostream>
using namespace std;

class ChessPiece{
    string name, color;
    char uniqSymbl;
    public:
        ChessPiece():name("Pawn"), color("White"), uniqSymbl('P'){}
        ChessPiece(string n, string c, char uS):name(n), color(c), uniqSymbl(uS){}
        string getName(){return name;}
        string getColor(){return color;}
        char getUniqSymbl(){return uniqSymbl;}
        void setName(string n){name = n;}
        void setColor(string c){color = c;}
        void setUniqSymbl(char uS){uniqSymbl = uS;}
};
class ChessBoard{
    ChessPiece*** board;
    public:
        ChessBoard(){
            board = new ChessPiece**[8];
            for(int i=0;i<8;i++){
                board[i] = new ChessPiece*[8];
            }
            board[0][0] = new ChessPiece("Rook","Black",'R');
            board[0][1] = new ChessPiece("Knight","Black",'N');
            board[0][2] = new ChessPiece("Bishop","Black",'B');
            board[0][3] = new ChessPiece("Queen","Black",'Q');
            board[0][4] = new ChessPiece("King","Black",'K');
            board[0][5] = new ChessPiece("Bishop","Black",'B');
            board[0][6] = new ChessPiece("Knight","Black",'N');
            board[0][7] = new ChessPiece("Rook","Black",'R');
            for(int i=0;i<8;i++){
                board[1][i] = new ChessPiece("Pawn","Black",'P');
            }
            for(int i=2;i<6;i++){
                for(int j=0;j<8;j++){
                    board[i][j] = nullptr;
                }
            }
            for(int i=0;i<8;i++){
                board[6][i] = new ChessPiece("Pawn","White",'p');
            }
            board[7][0] = new ChessPiece("Rook","White",'r');
            board[7][1] = new ChessPiece("Knight","White",'n');
            board[7][2] = new ChessPiece("Bishop","White",'b');
            board[7][3] = new ChessPiece("Queen","White",'q');
            board[7][4] = new ChessPiece("King","White",'k');
            board[7][5] = new ChessPiece("Bishop","White",'b');
            board[7][6] = new ChessPiece("Knight","White",'n');
            board[7][7] = new ChessPiece("Rook","White",'r');
        }
        void display(){
            cout<<"  a b c d e f g h"<<endl;
            for(int i=0;i<8;i++){
                cout<<8-i<<" ";
                for(int j=0;j<8;j++){
                    if(board[i][j]!=nullptr)
                    cout<<board[i][j]->getUniqSymbl()<<" ";
                    else
                    cout<<". ";
                }
                cout<<8-i<<" ";
                cout<<endl;
            }
            cout<<"  a b c d e f g h"<<endl;
        }
        bool movePiece(string source, string destination){
            int sRow = 8-(source[1]-'0');
            int sCol = source[0]-'a';
            int dRow = 8-(destination[1]-'0');
            int dCol = destination[0]-'a';
            bool moveAllow = false;
            if(board[sRow][sCol]==nullptr){
                cout<<"No piece at source"<<endl;
                return false;
            }
            else if(board[sRow][sCol]->getName()=="Pawn"){
                if(board[sRow][sCol]->getColor()=="White" && ((sRow-dRow)==1 || ((sRow-dRow)==2 && board[sRow-1][sCol]==nullptr)) && (board[dRow][dCol]==nullptr || board[dRow][dCol]->getColor()=="Black"))
                    moveAllow = true;
                else if(board[sRow][sCol]->getColor()=="Black" && ((dRow-sRow)==1 || ((dRow-sRow)==2 && board[sRow+1][sCol]==nullptr)) && (board[dRow][dCol]==nullptr || board[dRow][dCol]->getColor()=="White"))
                    moveAllow = true;
            }
            else if(board[sRow][sCol]->getName()=="Knight"){
                if(board[sRow][sCol]->getColor()=="White" && ((abs(dRow-sRow)==2 && abs(dCol-sCol)==1) || (abs(dRow-sRow)==1 && abs(dCol-sCol)==2)) && (board[dRow][dCol]==nullptr || board[dRow][dCol]->getColor()=="Black"))
                    moveAllow = true;
                else if(board[sRow][sCol]->getColor()=="Black" && ((abs(dRow-sRow)==2 && abs(dCol-sCol)==1) || (abs(dRow-sRow)==1 && abs(dCol-sCol)==2)) && (board[dRow][dCol]==nullptr || board[dRow][dCol]->getColor()=="White"))
                    moveAllow = true;
            }
            else if(board[dRow][dCol]!=nullptr){
                moveAllow = true;
            }
            if(moveAllow){
                board[dRow][dCol] = board[sRow][sCol];
                board[sRow][sCol] = nullptr;
                return true;
            }
            else
                return false;

        }
    ~ChessBoard(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]!=nullptr)
                    delete board[i][j];
            }
            delete [] board[i];
        }
        delete [] board;
    }
};
void displayRollNum(){
    cout<<"----------------------------"<<endl<<"|  Sahil Latif <<23I0763>> |"<<endl<<"----------------------------"<<endl;
}
int main(){
    displayRollNum();
    ChessBoard cb;
    cb.display();
    if(cb.movePiece("b1","c3"))
        cout<<"Moved Successfully"<<endl;
    else
        cout<<"Move not allowed"<<endl;
    cb.display();
    if(cb.movePiece("c3","e4"))
        cout<<"Moved Successfully"<<endl;
    else
        cout<<"Move not allowed"<<endl;
    cb.display();
    if(cb.movePiece("e4","f6"))
        cout<<"Moved Successfully"<<endl;
    else
        cout<<"Move not allowed"<<endl;
    cb.display();
    if(cb.movePiece("f7","d5"))
        cout<<"Moved Successfully"<<endl;
    else
        cout<<"Move not allowed"<<endl;
    cb.display();
    if(cb.movePiece("b2","b3"))
        cout<<"Moved Successfully"<<endl;
    else
        cout<<"Move not allowed"<<endl;
    cb.display();


    return 0;
}