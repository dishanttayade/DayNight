#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Amit The Bro Programmer  Creator of The Server

class Validator{
    private:
    Validator(){}
    public:
    static bool isValidMIMEType(string &mimetype){
        return true;
    }
    static bool isValidPath(string &path){
        return true;
    }
    static bool isValidURL(string &url){
        return true;
    }
};


class Error{

    public:
    bool hasError(){
        return false;
    }
    string getError(){
        return "";
    }
};


class Request{

};


class Response{

    private:
    string contentType;
    public:
    void setContentType(string contentType){
        if(Validator :: isValidMIMEType(contentType)){
            this->contentType = contentType;
        }
    }
    Response & operator<<(string content){
        //right now do nothing
        return *this;
    }

};


class Bro{

    private:
    string staticResourcesFolder;
    map<string,void (*)(Request &, Response &)> urlMappings;
    public:
    Bro(){

    }
    ~Bro(){

    }
    void setStaticResourcesFolder(string staticResourcesFolder){
        if(Validator:: isValidPath(staticResourcesFolder)){
            this->staticResourcesFolder = staticResourcesFolder;
        }
    }
    void get(string url, void (*callBack)(Request &, Response &)){
        if(Validator::isValidURL(url)){
            urlMappings.insert(pair<string, void (*)(Request &, Response &)>(url,callBack));
        }
    }              //Second One Should Be Capable of Storing address of a Anonymous Or Lambda Function(Pointer to a function)
    void listen(int portNumber,void(*callBack)(Error &)){
        //do nothing right now
    }
};

//Bobby The Web Application Developer - User of Bro Web Server

int main(){
    Bro bro;
    bro.setStaticResourcesFolder("ResourcesFolder");

    bro.get("/",[](Request &request, Response &response) void{   //Pointer is pointing to the base address
        const char *html = R""""(                                 
            <!Doctype HTML>
            <html lang = 'en'>
            <head>
            <meta charset = 'utf-8'>
            <title> Test </title>
            </head>
            <body>
            <h1>Hello</h1>
            <h3>Customers List</h3>
            <a href='getCustomers'>List of Customers</a>
            </body>
            </html>
        )"""";

        response.setContentType("text/html");
        response<<html;
    });               //Creating an anomymous funtion or a Lambda Function Capture -> [] and {} -> Body Part


    bro.get("/getcustomers", [](Request &request, Response &response) void{
        const char *html = R""""(
            <Doctype HTML>
            <html lang = 'en'>
            <head>
            <meta charset = 'utf-8'>
            <title>Customers</title>
            </head>
            <body>
            <h1>List of Customers</h1>
            <ul>
            <li>Ramesh</li>
            <li>Suresh</li>
            <li>Mohan</li>
            </ul>
            <a href = '/'> Home </a>
            </body>
            </html>
        )"""";
        response.setContentType("text/html"); //Setting MIME Type
        response<<html;
    });


    bro.listen(6060,[](Error &error)void{
        if(error.hasError()){
            cout<<error.getError();
            return;
        }
        cout<<"Ready to accept request on Port 6060"<<"\n";
    });


    return 0;
}


/*
Things To learn Yourself
    C++ Multithreading Example
    Creating A Socket Server in Cpp 
*/
