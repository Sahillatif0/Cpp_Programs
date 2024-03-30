
#include<iostream>
using namespace std;

class SecurityTool{
    int cost, numDevices;
    string securityLevel;
    public:
        SecurityTool(string securityLevel, int cost, int numDevices):numDevices(numDevices){
            if(securityLevel == "Low" || securityLevel == "Medium" || securityLevel == "High")
                this->securityLevel = securityLevel;
            else{
                cout<<"Invalid Security Level"<<endl;
                inputSecurityLvl();
            }
            if(cost>0)
                this->cost = cost;
            else{
                cout<<"Invalid cost"<<endl;
                inputCost();
            }
        }
        void inputSecurityLvl(){
            string securityLevel;
            while(securityLevel != "Low" && securityLevel != "Medium" && securityLevel != "High"){
                cout<<"Enter security Level again: ";
                cin>>securityLevel;
        }
            this->securityLevel = securityLevel;
        }
        void inputCost(){
            int cost;
            while(cost<=0){
                cout<<"Enter cost again: ";
                cin>>cost;
            }
            this->cost = cost;
        }
        void performScan(){
            cout<<"Performing scan..."<<endl;
        }
        string getSecurityLvl(){
            return securityLevel;
        }
        void setSecurityLvl(string lvl){
            if(lvl == "Low" || lvl == "Medium" || lvl == "High")
                securityLevel = lvl;
            else{
                cout<<"Invalid Security Level"<<endl;
                inputSecurityLvl();
            }
        }
};

class FirewallTool: public SecurityTool{
    int* ports;
    string *protocols;
    int numPorts, numProtocols;
    public:
        FirewallTool(string securityLevel, int cost, int numDevices):SecurityTool(securityLevel, cost, numDevices), numPorts(0), numProtocols(0){}
        void generateList(int num){
            if(num==0)
                num = 1;
            ports = new int[23];
            for(int i=0; i<23; i++){
                ports[i] = ++num; 
                numPorts++;
            }
            protocols = new string[6];
            protocols[0] = "HTTPS";
            protocols[1] = "FTP";
            protocols[2] = "UDP";
            protocols[3] = "ICMP";
            protocols[4] = "SSH";
            protocols[5] = "SNMP";
            numProtocols = 6;
        }
        void performScan(int port, string protocol){
            int portFound = 0, protocolFound = 0;
            if(getSecurityLvl() == "High"){
                for(int i=0;i<numPorts;i++)
                    if(ports[i] == port){
                        portFound  = 1;
                        break;
                    }
                if(portFound == 0){
                    cout<<"Traffic from "<<port<<" isn't allowed"<<endl;
                    return;
                }
                for(int i=0;i<numProtocols;i++)
                    if(protocols[i] == protocol){
                        cout<<"Traffic is allowed"<<endl;
                        protocolFound  = 1;
                        return;
                    }
                if(protocolFound == 0){
                    cout<<"Traffic from "<<protocol<<" isn't allowed"<<endl;
                    return;
                }
            }
            else if(getSecurityLvl() == "Medium"){
                for(int i=0;i<numPorts;i++)
                    if(ports[i] == port){
                        portFound  = 1;
                        break;
                    }
                if(portFound == 0){
                    if(ports[numPorts-1]+1 == port || ports[numPorts-1]+2 == port)
                        portFound = 1;
                    else{
                        cout<<"Traffic from "<<port<<" isn't allowed"<<endl;
                        return;
                    }
                }
                for(int i=0;i<numProtocols;i++)
                    if(protocols[i] == protocol){
                        cout<<"Traffic is allowed"<<endl;
                        protocolFound  = 1;
                        return;
                    }
                if(protocolFound == 0){
                    cout<<"Traffic from "<<protocol<<" isn't allowed"<<endl;
                    return;
                }
            }
            else if(getSecurityLvl()=="Low"){
                for(int i=0;i<numPorts;i++)
                    if(ports[i] == port){
                        portFound  = 1;
                        break;
                    }
                if(portFound == 0){
                    if(ports[numPorts-1] < port && ports[numPorts-1]+5 >= port)
                        portFound = 1;
                    else{
                        cout<<"Traffic from "<<port<<" isn't allowed"<<endl;
                        return;
                    }
                }
                for(int i=0;i<numProtocols;i++)
                    if(protocols[i] == protocol){
                        cout<<"Traffic is allowed"<<endl;
                        protocolFound  = 1;
                        return;
                    }
                if(protocolFound == 0){
                    if(protocol == "TCP" || protocol == "DNS")
                        cout<<"Traffic is allowed"<<endl;
                    else
                        cout<<"Traffic from "<<protocol<<" isn't allowed"<<endl;
                    return;
                }
            }
        }
    ~FirewallTool(){
        delete[] ports;
        delete[] protocols;
    }
};
int main() {
    cout<<endl<<endl<<"Coded By: Sahil Latif (23i0763)"<<endl<<endl;
    FirewallTool f1("High", 1000, 5);
    f1.generateList(7);
    f1.performScan(23, "HTTPS");
    f1.performScan(33, "HTTPS");
    f1.performScan(13, "DNS");
    f1.setSecurityLvl("Medium");
    f1.performScan(15, "DNS");
    f1.performScan(23, "ICMP");
    f1.performScan(32, "SSH");
    f1.setSecurityLvl("Low");
    f1.performScan(34, "UDP");
    f1.performScan(36, "UDP");
    f1.performScan(23, "SNMP");
    f1.performScan(23, "DNS");
    return 0;
}