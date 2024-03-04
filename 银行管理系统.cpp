#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
#include<strstream>
#include<conio.h>
using namespace std;
class Function;
class User
{
public:
    void get( );
    friend class Function;
    void print();
    void PassWord();
    void SaveFile(User &);
    vector<string> StrFunction;
    User(){}
    User(int A,string N,int F,string I,string Ad,int T):Accout(A),Name(N),Fmoney(F),ID(I),Address(Ad),Telephone(T){}
private:
  int Accout;//账号
  string Name;//姓名
  int Fmoney;
  string ID;
  string Address;
  int Telephone;
  char  Pword1[9];
  char Pword2[9];
};
class Function
{
public:
    void Saving(User &);
    void Drawing(User &);
    void Balance(User &);
    void Record(User &);
private:
    int  SaveAndDrawMoney;
 
 
};
void Function::Saving(User &u)
{
 system("cls");
 cout<<"\n\n\n\t\t*********************************************\n"<<endl;
 cout<<"\t\t请输入存款金额：";
 string str1("现存 RMB  钞 +   ");
 cin>>SaveAndDrawMoney;
 u.Fmoney+=SaveAndDrawMoney;
 strstream ss;//输入输出字符串类
 string  str2;
 ss<<SaveAndDrawMoney;
 ss>>str2;
 str1=str1+str2;
 u.StrFunction.push_back(str1);
 cout<<"\n\n\t\t操作成功，单击任何键返回主菜单！";
 getch();
}
void Function::Drawing(User &u)
{
  system("cls");
  cout<<"\n\n\n\t\t*********************************************\n"<<endl;
  cout<<"\t\t请输入取款金额：";
  string str("现取 RMB  钞 -   ");
  int k=0;
  while(k<=3)
  {
      int Money;
    cin>>SaveAndDrawMoney;
    Money=u.Fmoney -SaveAndDrawMoney;
   if(Money>=0)
  {
     system("cls");
    cout<<"\n\n\n\t\t正在出炒，请稍等！"<<endl;
    strstream ss;
    string  str2;
    ss<<SaveAndDrawMoney;
    ss>>str2;
    str=str+str2;
    u.StrFunction.push_back(str);
    break;
  }
  else
  {
      k++;
      if(k>=3)
      {
      system("cls");
      cerr<<"\n\n\n\t\t很抱歉，你重复输入错误多次"<<endl
            <<"\n\t\t正在退卡中……"<<endl;
      exit(0);
      }
      system("cls");
      cerr<<"\n\n\n\t\t对不起，你输入的金额超出有效金额。"<<endl
          <<"\n\t\t       请重新输入:  ";
  }
  }
  cout<<"\n\n\t\t操作成功，单击任何键返回主菜单！";
  getch();
}
void Function::Balance(User &u)
{
  system("cls");
  cout<<"\n\n\n\t\t*********************************************\n"<<endl;
  cout<<"\t\t你当前的余额是：";
  cout<<"\t\t"<<u.Fmoney<<endl;
  cout<<"\n\t\t*********************************************\n"<<endl;
  cout<<"\n\t\t操作成功，单击任何键返回主菜单！";
  getch();
}
void Function::Record(User &u)
{
    system("cls");
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
    cout<<"\t\t摘要 币种 钞汇 存/取款金额"<<endl;
    vector<string>::iterator  iter,iend;
    iter=u.StrFunction.begin();
    for(iter;iter!=u.StrFunction.end();iter++)
        cout<<"\n\t\t"<<*iter<<endl;
    cout<<"\n\t\t*********************************************\n"<<endl;
    cout<<"\n\t\t操作成功，单击任何键返回主菜单！";
    getch();
}
void User::print() //mark
{
    system("cls");
 cout<<"\n\n\n\t\t*********************************************\n"<<endl;
 cout<<"\n\t\t用户卡号： "<<Accout<<endl;
 cout<<"\n\t\t姓名：     "<<Name <<endl;
 cout<<"\n\t\t开户金额： "<<Fmoney<<endl;
 cout<<"\n\t\t身份证号： "<<ID<<endl;
 cout<<"\n\t\t地址：     "<<Address <<endl;
 cout<<"\n\t\t联系电话： "<<Telephone <<endl;
 cout<<"\n\t\t密码：     "<<Pword1<<endl;
 cout<<"\n\t\t*********************************************\n"<<endl;
 cout<<"\n\t\t操作成功，单击任何键返回主菜单！";
 getch();
 return ;
}
void User::SaveFile(User &u)
{
    ofstream outfile("outfile.txt", ios::trunc );//trunc如果文件存在就打开并清除其内容,如不存在就建立新文件
    cout<<"\n\n\n\t\t*********************************************\n"<<endl;
   outfile<<"\t\t用户卡号： "<<Accout<<endl
             <<"\t\t姓名： "<<Name<<endl
             <<"\t\t开户金额： "<<Fmoney<<endl
             <<"\t\t身份证号： "<<ID<<endl
             <<"\t\t地址： "<<Address<<endl
             <<"\t\t联系电话： "<<Telephone<<endl
             <<"\t\t密码： "<<Pword1<<endl;
   cout<<"\n\t\t*********************************************\n"<<endl;
   outfile.close();
}
void User::PassWord()
{
   int num=0;
 while(num<3)
 {
  cout<<"\n\t\t请输入8位储蓄密码：";
 for(int i=0;i<8;i++)
 { Pword1[i]=getch();cout<<"*";}
   Pword1[8]='\0';
   cout<<endl;
   cout<<"\n\t\t请再一次确认密码：";
   for(int j=0;j<8;j++)
   { Pword2[j]=getch();cout<<"*";}
   cout<<endl;
   Pword2[8]='\0';
 if(strcmp(Pword1,Pword2)==0)
 {
     cout<<"\n\n\t\t密码确认成功，单击任何键进入主菜单";
    getch();
    return ;
 }
 else
 {
     num++;
     cout<<"\n\t\t你输入的密码错误，请重新输入！\n"<<endl;
 }
 if(num==3)
 {
     system("cls");
     cerr<<"\n\n\n\t\t对不起，你三次输入不正确\n"<<endl
            <<"\t\t感谢你的使用，再见！    "<<endl;
     exit(0);
 }
 }
}
void User::get()
{
    system("cls");
   cout<<"\n\n\n\t\t请输入用户信息：\n"<<endl;
   cout<<"\t\t*********************************************\n"<<endl;
   cout<<"\n\t\t卡号：";
   cin>>Accout;
   cout<<"\n\t\t姓名：";
   cin>>Name;
   cout<<"\n\t\t开户金额：";
   cin>>Fmoney;
   cout<<"\n\t\t身份证号：";
   cin>>ID;
   cout<<"\n\t\t地址：";
   cin>>Address;
   cout<<"\n\t\t联系电话：";
   cin>>Telephone;
   PassWord();
   cout<<"\n\t\t*********************************************\n"<<endl;
}
void Sign()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t谢谢您使用银行管理系统 \t \n\n"<<endl;
    cout<<"\t\t*********************************************\n"<<endl;
    cout<<"\t\t         姓名: 孙楠    \n\n"
           <<"\t\t         班级: 计算机201班\n\n"
           <<"\t\t         学号: 2202004166\n\n"<<endl;
     cout<<"\n\t\t         已经成功退出"<<endl
            <<"\n\t\t         欢迎你的光临！" <<endl;
}
char custom(User &u)
{
      char x;
    system("cls");
cout<<"\n\n\n\t\t※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※            欢迎使用储蓄管理系统                   ※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※            请用户在使用前选择开户：               ※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※            请选择：                               ※\n"
        <<"\t\t※                单击“1”选择开户                  ※\n"
        <<"\t\t※                单击其他将退出                     ※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※                                                   ※\n"
        <<"\t\t※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"<<endl;
         cout<<"\n\t\t请选择操作方式： ";
         cin>>x;
         if(x=='1')
         {
            u.get();
         }
         else
         {
             Sign();
             exit(0);
         }
         return 0;
}
char menu()
{
  int k=0;
  char a[3],c,i;
    system("cls");
    cout<<"\n\n\n\t\t                主菜单          \n\n" ;
    cout<<"\t\t*********************************************\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*     操作方式:                             *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             1.存款       2.取款           *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             3.查询余额   4.查询历史记录   *\n"
        <<"\t\t*                                           *\n"
        <<"\t\t*             5.用户信息   6.保存并退出     *\n"
        <<"\t\t*********************************************\n"<<endl;
        while(k<3)
        {
            cout<<"\n\t\t请选择操作方式:  ";
        cin>>a;
        if(strlen(a)==1)
        {
            for(i='1';i<='6';i++)
            {  c=i;
            if(c==a[0]) return c;
            }
        }
        else
        {
            system("cls");
        cerr<<"\n\n\n\t\t\t输入有误!\n"<<endl
              <<"\t\t\t请重新输入： "<<endl;
        k++;
        }
        while(k>=3)
        {
            system("cls");
          cerr<<"\n\n\n\t\t对不起，你三次输入不正确\n"<<endl
             <<"\n\t\t感谢你的使用，再见！\n"<<endl;
            exit(0);
        }
        }
        return c;
    }
char Choose(  User &u,Function &F)
{
  char c=menu();
  while(c!='6')
  {
      switch(c)
  {
  case '1': F.Saving(u);c=menu();break;
  case '2':F.Drawing(u);c=menu();break;
  case '3':F.Balance(u);c=menu();break;
  case '4':F.Record(u);c=menu();break;
  case '5':u.print();c=menu();break;
  }
 
 
  }
  u.SaveFile(u);
  Sign();
  return 0;
}
int main()
{
  User u;//用户类
  Function F;
  vector<Function> FunctionUser;
  custom(u);
  Choose(u,F);
}
