#pragma once
#include<string>
#include<iostream>
using namespace std;

class Error{
protected:
    string msg;
public:
    virtual void what(){};
};

class IndexError:public Error{
protected:
    string msg;
public:
    IndexError(){msg="Index Error\n";}
    virtual void what(){cout<<msg;}
};

class Index_min_error:public IndexError{
protected:
    string msg_;
public:
    Index_min_error(){IndexError();msg_="Index<MinIndex\n";}
    virtual void what(){cout<<msg<<msg_;}
};
class Index_max_error:public IndexError{
protected:
    string msg_;
public:
    Index_max_error(){IndexError();msg_="Index>MaxIndex\n";}
    virtual void what(){cout<<msg<<msg_;}
};
class size_error:public Error{
protected:
    string msg;
public:
    size_error(){msg="Index Error\n";}
    virtual void what(){cout<<msg;}
};
class error_empty :public size_error
{
protected:
    string msg_;
public:
    error_empty(){size_error();msg_ = "empty list";}
    virtual void what(){cout<<msg<<msg_;}
};

class error_diff_size :public size_error
{
protected:
    string msg_;
public:
    error_diff_size(){size_error();msg_= "Diff size of list";}
    virtual void what(){cout<<msg<<msg_;}
};