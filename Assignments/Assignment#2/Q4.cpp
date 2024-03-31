#include<iostream>
#include<cmath>
using namespace std;

class User{
    string username, email, password;
    public:
        User(string username, string email, string password):username(username), email(email){
            this->password = encode(password);
        }
        string encode(string pass){
            string hashedPass, salt = "iamsaltusedforencoding";
            pass.append(salt);
            int len = pass.length();
            for(int i=0;i<len;i++){
                for(int j=1;j<4;j++){
                    char c = char (pass[i]+pow(len%3+2,j));
                    hashedPass.push_back(c);
                }
            }
            hashedPass+=to_string(len%3+2);
            return hashedPass;

        }
        string decode(string hash){
            string pass, salt = "iamsaltusedforencoding";
            for(int i=0;i<hash.length();i+=3){
                char c = char (hash[i]- (hash[hash.length()-1])) + '0';
                pass.push_back(c);
            }
            pass.resize(pass.length()-salt.length()-1);
            return pass;
        }
        string getUsername(){return username;}
};
class Post{
    int postID, likes,views, numComments;
    string content, *comments;
    static int totalPosts;
    public:
        Post(string content):postID(++totalPosts), content(content), likes(0),views(0), numComments(0){}
        void addComment(string comment){
            string *newCom = new string[numComments+1];
            for(int i=0;i<numComments;i++)
                newCom[i] = comments[i];
            newCom[numComments++] = comment;
            comments = newCom;
            views++;
        }
        int getLikes(){return likes;}
        int getViews(){return views;}
        int getNumComments(){return numComments;}
        void setLikes(int likes){this->likes = likes;}
        void setViews(int views){this->views = views;}
        void setNumComments(int numComments){this->numComments = numComments;}
        void likePost(){likes++;views++;}
        void displayDetails(){
            cout<<"PostID: "<<postID<<endl;
            cout<<"Content: "<<content<<endl;
            cout<<"Views: "<<views<<endl;
            cout<<"Likes: "<<likes<<endl;
            cout<<"Comments: "<<numComments<<endl;
            for(int i=0;i<numComments;i++)
                cout<<i+1<<". "<<comments[i]<<endl;
            cout<<endl;
            views++;
        }
};
int Post::totalPosts = 0;
class RegularUser:public User{
    protected:
        static int maxFeed;
        Post **myposts;
        Post **myfeed;
        int numPosts, numFeed;
    public: 
        RegularUser(string username, string email, string password):User(username, email, password),numPosts(0),numFeed(0){}
        void addPost(Post *post){
            if(numPosts<5){
                Post **newPosts = new Post*[numPosts+1];
                for(int i=0;i<numPosts;i++)
                    newPosts[i] = myposts[i];
                newPosts[numPosts++] = post;
                myposts = newPosts;
                addPostToFeed(post);
            }
            else
                cout<<"Max Posts limit reached"<<endl;
        }
        void addPostToFeed(Post *post){
            if(numFeed<maxFeed){
                Post **newPosts = new Post*[numFeed+1];
                for(int i=0;i<numFeed;i++)
                    newPosts[i] = myfeed[i];
                newPosts[numFeed++] = post;
                myfeed = newPosts;
            }
            else
                cout<<"Max Feed limit reached"<<endl;
        }
        void viewMyPosts(){
            cout<<endl<<"Username: "<<getUsername()<<endl<<endl;
            for(int i=0;i<numPosts;i++)
                myposts[i]->displayDetails();
        }
        void viewFeed(){
            for(int i=0;i<numFeed;i++)
                myfeed[i]->displayDetails();
        }
};
int RegularUser::maxFeed = 10;
class BusinessUser: public RegularUser{
    int numPromotedPosts;
    public:
        BusinessUser(string username, string email, string password):RegularUser(username, email, password), numPromotedPosts(0){}
        void promotePost(Post &post){
            if(numPromotedPosts<10){
                post.setLikes(post.getLikes()*2);
                post.setViews(post.getViews()*3);
                numPromotedPosts++;
            }
            else
                cout<<"Max Promoted Posts limit reached"<<endl;
        }
        void trackLikes(Post post){
            cout<<"Post Likes: "<<post.getLikes()<<endl;
        }
        void trackComments(Post post){
            cout<<"Post Comments: "<<post.getNumComments()<<endl;
        }
        void trackView(Post post){
            cout<<"Post Views: "<<post.getViews()<<endl;
        }
};

int main() {
    cout<<endl<<endl<<"Coded By: Sahil Latif (23i0763)"<<endl<<endl;
    Post posts[10] = {Post("Post 1"), Post("Post 2"), Post("Post 3"), Post("Post 4"), Post("Post 5"), Post("Post 6"), Post("Post 7"), Post("Post 8"), Post("Post 9"), Post("Post 10")};
    RegularUser u1("Sahil", "sahillatif@gmail.com", "Sahil123");
    BusinessUser u2("Ali", "alikhan786@yahoo.com","Ali123");
    u1.addPost(&posts[0]);
    u1.viewMyPosts();
    u1.addPost(&posts[2]);
    u1.addPost(&posts[3]);
    u1.addPost(&posts[4]);
    u1.addPost(&posts[5]);
    u1.addPost(&posts[8]);
    u2.addPost(&posts[1]);
    u2.addPost(&posts[6]);
    u2.addPost(&posts[7]);
    posts[1].addComment("Nice Post");
    posts[1].addComment("Great Post");
    posts[1].likePost();
    posts[2].likePost();
    posts[3].likePost();
    u1.addPostToFeed(&posts[1]);
    u1.addPostToFeed(&posts[6]);
    cout<<endl<<endl<<"Before Promoting Post"<<endl<<endl;
    u2.trackLikes(posts[1]);
    u2.trackComments(posts[1]);
    u2.trackView(posts[1]);
    u2.promotePost(posts[1]);
    cout<<endl<<endl<<"After Promoting Post"<<endl<<endl;
    u2.trackLikes(posts[1]);
    u2.trackComments(posts[1]);
    u2.trackView(posts[1]);
    cout<<endl;
    u2.viewMyPosts();
    u1.viewFeed();
}