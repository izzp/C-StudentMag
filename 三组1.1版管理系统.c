#include"stdio.h"
#include"windows.h"
#define  N  50 //学生人数
#define M  3  //课程的门数


/* 
	18.1.25中午的1.1版本
	Dev-c++5.10编译通过
	0错误，0警告 
	问题已全部解决 
	相比较24号下午的0.91版本，和25上午的1.0更加美化，修复了几处小错误 
	注释掉了背景音乐； 
	加入了成绩加密，打开储存信息的文件是看不出来成绩的
	可以查看任意前后名次 ；
	鼠标点击；（xp好用，win10有时点不了） 
	管理账号：admin密码：admin，登录后可修改 
	 
	只读写了一次文件，故最后要通过退出而退出 
*/ 


typedef struct                               
{ 
	int num ;         /*学号*/
	char name[20];   /*姓名*/
	int score[M];     /*各门课成绩*/
	int sum;        /*总分*/
   	int order;     /*名次*/			
}Info; /*定义结构体类型*/


Info  L[N];  /*定义结构体数组，保存学生信息的个数*/

int length=0;  /*保存学生的实际个数*/ 
 
HANDLE hout;
HWND h0ut;
int wzzt[2]={-1,-1};
CONSOLE_SCREEN_BUFFER_INFO	csbi;
WORD cols[] = {
	FOREGROUND_RED | FOREGROUND_INTENSITY, 		//红色
	FOREGROUND_RED, 							//浅红色
	FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 	//黄色
	FOREGROUND_GREEN | FOREGROUND_INTENSITY,	//绿色
	FOREGROUND_BLUE | FOREGROUND_INTENSITY, 	//蓝色
};
char letter[7][8][9] = {
	{
		0,0,0,0,0,0,0,0,0,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,1,
	},{
	   	0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
		0,1,0,0,0,0,0,0,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	},{
	
		0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,0,0,
	    0,1,0,0,0,0,0,1,0,
		0,1,0,0,0,0,0,1,0,
		0,1,0,0,0,0,0,1,0,
		0,1,0,0,0,0,0,1,0,
	    0,1,0,0,0,0,0,1,0,
		0,0,1,1,1,1,1,0,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,0,0,0,
		0,0,1,1,1,1,0,0,0,
	}
};
char letter1[7][8][9] = {
	{
		0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,0,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,1,
		1,1,1,1,1,1,1,0,0,
		1,0,0,0,0,0,0,1,1,
		1,0,0,0,0,0,0,0,1,
	   	1,1,1,1,1,1,1,1,0,
	},{
	   	0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
		0,1,0,0,0,0,0,0,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,1,0,
		0,0,1,0,0,0,1,0,0,
		0,0,0,1,0,1,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
	},{
	
		0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,0,
		1,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,1,
		1,1,1,1,1,1,1,0,0,
		1,0,0,0,0,0,0,1,1,
		1,0,0,0,0,0,0,0,1,
	   	1,1,1,1,1,1,1,1,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
		0,1,0,0,0,0,0,0,0,
	    0,1,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,1,0,
		0,0,1,0,0,0,1,0,0,
		0,0,0,1,0,1,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
	},{
		0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,0,0,0,
		0,0,1,1,1,1,0,0,0,
	}
};

Gotoxy(int x,int y)//定位函数 
{
    HANDLE h0ut;
    COORD pos={x,y};
    h0ut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h0ut,pos);
} 
void HideCursor0()//隐藏控制台的光标 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void HideCursor1()//显示控制台的光标 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 1}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void shubiaoxy()
{
	POINT pt = { 0, 0 };
	h0ut = FindWindow("ConsoleWindowClass", NULL);// 控制台句柄
	HideCursor0();//隐藏控制台的光标
	while (1)
	{
		if (GetKeyState(VK_LBUTTON) & 0x8000)
		{ 
			
			GetCursorPos(&pt);	//获取鼠标当前位置	
			ScreenToClient(h0ut, &pt);//相对窗口位置
			wzzt[0] = pt.x;
			wzzt[1] = pt.y;
			break;
		}
	}
}
void phone()
{
	Gotoxy(47,3);printf("◤▔▔▔▔▔▔▔▔▔▔◥\n");
	Gotoxy(47,4);printf("▎    ☉     ----      ▎\n");
	Gotoxy(47,5);printf("▎-------------------- ▎\n");
	Gotoxy(47,6);printf("▎                     ▎\n");
	Gotoxy(47,7);printf("▎                     ▎\n");
	Gotoxy(47,8);printf("▎                     ▎\n");
	Gotoxy(47,9);printf("▎                     ▎\n");
	Gotoxy(47,10);printf("▎                     ▎\n");
	Gotoxy(47,11);printf("▎                     ▎\n");
	Gotoxy(47,12);printf("▎                     ▎\n");
	Gotoxy(47,13);printf("▎                     ▎\n");
	Gotoxy(47,14);printf("▎                     ▎\n");
	Gotoxy(47,15);printf("▎                     ▎\n");
	Gotoxy(47,16);printf("▎                     ▎\n");
	Gotoxy(47,17);printf("▎                     ▎\n");
	Gotoxy(47,18);printf("▎                     ▎\n");
	Gotoxy(47,19);printf("▎                     ▎\n");
	Gotoxy(47,20);printf("▎                     ▎\n");
	Gotoxy(47,21);printf("▎                     ▎\n");
	Gotoxy(47,22);printf("▎                     ▎\n");
	Gotoxy(47,23);printf("▎▁▁▁▁▁▁▁▁▁▁ ▎\n");
	Gotoxy(47,24);printf("▎         ◎          ▎\n");
	Gotoxy(47,25);printf("◣▂▂▂▂▂▂▂▂▂▂◢");
}
void phone1()
{
	Gotoxy(47,3);printf("◤▔▔▔▔▔▔▔▔▔▔◥\n");
	Gotoxy(47,4);printf("▎    ☉     ----      ▎\n");
	Gotoxy(47,5);printf("▎-------------------- ▎\n");
	Gotoxy(47,6);printf("▎                     ▎\n");
	Gotoxy(47,7);printf("▎                     ▎\n");
	Gotoxy(47,8);printf("▎                     ▎\n");
	Gotoxy(47,9);printf("▎                     ▎\n");
	Gotoxy(47,10);printf("▎             .:'     ▎\n");
	Gotoxy(47,11);printf("▎        __ :'__      ▎\n");
	Gotoxy(47,12);printf("▎    .'`   `-' ``.    ▎\n");
	Gotoxy(47,13);printf("▎   :          .-'    ▎\n");
	Gotoxy(47,14);printf("▎   :          :      ▎\n");
	Gotoxy(47,15);printf("▎   :          `-;    ▎\n");
	Gotoxy(47,16);printf("▎    `. __.-.__ .     ▎\n");
	Gotoxy(47,17);printf("▎                     ▎\n");
	Gotoxy(47,18);printf("▎                     ▎\n");
	Gotoxy(47,19);printf("▎                     ▎\n");
	Gotoxy(47,20);printf("▎                     ▎\n");
	Gotoxy(47,21);printf("▎                     ▎\n");
	Gotoxy(47,22);printf("▎                     ▎\n");
	Gotoxy(47,23);printf("▎▁▁▁▁▁▁▁▁▁▁ ▎\n");
	Gotoxy(47,24);printf("▎         ◎          ▎\n");
	Gotoxy(47,25);printf("◣▂▂▂▂▂▂▂▂▂▂◢");
}
void DrawWord(int color)
{
	int row, col, cut;//行，列，个数
	COORD pos;		//坐标，用于光标的定位
	DWORD dwLen;	//无符号整型
	color=color/2;
	for(cut = 0; cut < 7; cut++)	//按照字符个数循环
	{
		for(row = 0; row < 8; row++)	//每字符8行
		{
			//把光标定位到该行的行首位置
			pos.X = cut * 10+25;
			pos.Y = row+7;
			SetConsoleCursorPosition(hout, pos);	//把光标定位到pos指定的位置
			for(col = 0; col < 9; col++)	//每字符9列
			{
				if(letter[cut][row][col] == 1)
				{
					GetConsoleScreenBufferInfo(hout, &csbi);
					printf("*");
					//上色
					FillConsoleOutputAttribute(hout, cols[color],1,csbi.dwCursorPosition, &dwLen);
					color=color+1;
					if(color==5)
						color=0;
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}

void jindutiao(int i)
{
	Gotoxy(49,16);
	printf("---------------------------------");
	Gotoxy(35,17);
	printf("Please waiting:                              ");
	Gotoxy(49,18);
	printf("---------------------------------");
	i=i%22;
	Gotoxy(50+i,17);printf("····· ");
}

void DrawWord1(int color)
{
	int row, col, cut;//行，列，个数
	COORD pos;		//坐标，用于光标的定位
	DWORD dwLen;	//无符号整型
	color=color/2;
	for(cut = 0; cut < 7; cut++)	//按照字符个数循环
	{
		for(row = 0; row < 8; row++)	//每字符8行
		{
			//把光标定位到该行的行首位置
			pos.X = cut * 10+25;
			pos.Y = row+7;
			SetConsoleCursorPosition(hout, pos);	//把光标定位到pos指定的位置
			for(col = 0; col < 9; col++)	//每字符9列
			{
				if(letter1[cut][row][col] == 1)
				{
					GetConsoleScreenBufferInfo(hout, &csbi);
					printf("*");
					//上色
					FillConsoleOutputAttribute(hout, cols[color],1,csbi.dwCursorPosition, &dwLen);
					color=color+1;
					if(color==5)
						color=0;
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}
void jindutiao1(int i)
{
	Gotoxy(49,16);
	printf("---------------------------------");
	Gotoxy(35,17);
	printf("保 存 退 出 中:                              ");
	Gotoxy(49,18);
	printf("---------------------------------");
	i=i%22;
	Gotoxy(50+i,17);printf("····· ");
}
void listSaveN()    //把数组的长度length值保存到D:\num.txt文件中。
{
	FILE *f;
	int i;
	f=fopen("数据\\num.txt","w");
	if(f==0)
	printf("无文件\n");
	fprintf(f,"%d",length); 
	fclose(f);	
} 
void listLoadN()    //把文件中元素的个数导入length中。
{
	FILE *f;
	int i;
	f=fopen("数据\\num.txt","r");
	if(f==0)
	printf("无文件\n");
	fscanf(f,"%d",&length);
	fclose(f);
}
void listSort()     //排序 包括求和 
{
	int i,j;
	Info t;
	for(i=0;i<=length;i++)
	{
		L[i].sum=0;
		for(j=0;j<3;j++)
		{
			L[i].sum=L[i].score[j]+L[i].sum;
		} 
	}
	for(i=0;i<length;i++)
	{
		for(j=0;j<length-i;j++)
			if(L[j].sum<L[j+1].sum)
			{
				t=L[j];
				L[j]=L[j+1];
				L[j+1]=t;
			}
	}
}

void listLoad() //读
{
	int i,j;
	FILE *fp;
	fp=fopen("数据\\chengji.txt","r");	
	if(fp==NULL)
	{
		printf("不能打开该文件\n");
	}
	for(i=0;i<length;i++)
	{
	    fscanf(fp,"%d",&L[i].num);
	    L[i].num=(L[i].num-5257)/5257;
	    fscanf(fp,"%s",L[i].name);
	    for(j=0;j<M;j++)
	    {
	    	fscanf(fp,"%d",&L[i].score[j]);
	    	L[i].score[j]=(L[i].score[j]-5257)/5257;
		}
	    fscanf(fp,"%d",&L[i].sum);
	    L[i].sum=(L[i].sum-5257)/5257;
	    fscanf(fp,"%d",&L[i].order);
	    L[i].order=(L[i].order-5257)/5257;
	}
	fclose(fp);	
 } 
void listSave()  //写 
{
	int i,j;
	FILE *fp;
	fp=fopen("数据\\chengji.txt","w");
	for(i=0;i<length;i++)      
      {
         fprintf(fp,"%d\t%s\t",L[i].num*5257+5257,L[i].name);
         for(j=0;j<M;j++)
         { 
           fprintf(fp,"%d\t",L[i].score[j]*5257+5257);
         }
         L[i].order=i+1;
         fprintf(fp,"%d\t%d\t\n",L[i].sum*5257+57,L[i].order*5257+57);
      }

	fclose(fp);	
} 

int printMenu0()//主菜单 
{
	SetConsoleTitle("主菜单");//设置窗口标题 
	Sleep(200); 
    phone();		
	do
	{
	Gotoxy(40,8);printf("       ▎  主菜单");
	Gotoxy(40,11);printf("       ▎     「管理登录」");
	Gotoxy(40,13);printf("       ▎     「成绩查询」");
	Gotoxy(40,15);printf("       ▎     「  关于  」");
	Gotoxy(40,17);printf("       ▎     「  退出  」"); 	
	shubiaoxy();
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>175&&wzzt[1]<190)
	{
		return 2;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>210&&wzzt[1]<225)
	{
		return 3;
	}
	if(wzzt[0]>430&&wzzt[0]<480&&wzzt[1]>240&&wzzt[1]<255)
	{
		return 4;
	}
	if(wzzt[0]>430&&wzzt[0]<480&&wzzt[1]>275&&wzzt[1]<290)
	{
		return 5;
	}
	}while(1);
}
int printMenu1() //管理员菜单 
{
	
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单");//设置窗口标题
	system("CLS");	
	Sleep(200); 
	phone();	
	do
	{
	Gotoxy(40,8);printf("       ▎*管理菜单* ");
	Gotoxy(40,11);printf("       ▎    「录入成绩」");
	Gotoxy(40,13);printf("       ▎    「删除成绩」");
	Gotoxy(40,15);printf("       ▎    「更改成绩」 ");
	Gotoxy(40,17);printf("       ▎    「查看成绩」 ");
	Gotoxy(40,19);printf("       ▎    「修改密码」 ");
	Gotoxy(40,21);printf("       ▎    「返回上层」 "); 
	shubiaoxy();
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>175&&wzzt[1]<190)
	{
		return 2;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>210&&wzzt[1]<225)
	{
		return 3;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>240&&wzzt[1]<255)
	{
		return 4;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>275&&wzzt[1]<290)
	{
		return 5;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>305&&wzzt[1]<320)
	{
		return 6;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>335&&wzzt[1]<350)
	{
		return 7;
	}
	}while(1);
} 
int printMenu2()  //成绩查询菜单 
{
	Sleep(200); 
	SetConsoleTitle("主菜单 -> 成绩查询");//设置窗口标题 
	phone();	
	do
	{
		Gotoxy(40,8);printf("       ▎成绩查询");
		Gotoxy(40,11);printf("       ▎    「成绩单查询」 ");
		Gotoxy(40,13);printf("       ▎    「按姓名查询」 ");
		Gotoxy(40,15);printf("       ▎    「按学号查询」 ");
		Gotoxy(40,17);printf("       ▎    「返回  上层」 "); 
		shubiaoxy();
		if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>175&&wzzt[1]<190)
		{
			return 2;
		}
		if(wzzt[0]>430&&wzzt[0]<550&&wzzt[1]>210&&wzzt[1]<225)
		{
			return 3;
		}
		if(wzzt[0]>430&&wzzt[0]<550&&wzzt[1]>240&&wzzt[1]<255)
		{
			return 4;
		}
		if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>275&&wzzt[1]<290)
		{
			return 5;
		}	
	}while(1);
}
int printMenu3()//录入选择菜单 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 录入选择菜单");//设置窗口标题
	Sleep(200); 
    phone();		
	do
	{
		Gotoxy(40,8);printf("       ▎ 录入选择菜单");
		Gotoxy(40,11);printf("       ▎    「首次录入」");
		Gotoxy(40,13);printf("       ▎    「添加学生」");
	
		shubiaoxy();
		if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>175&&wzzt[1]<190)
		{
			return 2;
		}
		if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>210&&wzzt[1]<225)
		{
			return 3;
		}
	}while(1);
}
int printMenu4()//查看成绩菜单 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩");//设置窗口标题
	Sleep(200); 
    phone();		
	do
	{
	Gotoxy(40,8);printf("       ▎  查看成绩");
	Gotoxy(40,11);printf("       ▎     「所有成绩」");
	Gotoxy(40,13);printf("       ▎     「输出前几」");
	Gotoxy(40,15);printf("       ▎     「输出倒几」");
	Gotoxy(40,17);printf("       ▎     「返回上级」"); 	
	shubiaoxy();
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>175&&wzzt[1]<190)
	{
		return 2;
	}
	if(wzzt[0]>430&&wzzt[0]<510&&wzzt[1]>210&&wzzt[1]<225)
	{
		return 3;
	}
	if(wzzt[0]>430&&wzzt[0]<480&&wzzt[1]>240&&wzzt[1]<255)
	{
		return 4;
	}
	if(wzzt[0]>430&&wzzt[0]<480&&wzzt[1]>275&&wzzt[1]<290)
	{
		return 5;
	}
	}while(1);
}
int admin()		 //管理员登陆 
{
	
	SetConsoleTitle("主菜单 -> 管理登陆");//设置窗口标题 
	system("CLS");	 
	char zh0[30],zh1[30],mm0[30],mm1[30];	
	phone();
	Gotoxy(47,9);printf("▎***管理登陆*********");
	Gotoxy(47,11);printf("▎********************");
	Gotoxy(47,12);printf("▎|账 号：           |");
	Gotoxy(47,13);printf("▎-------------------|");
	Gotoxy(47,14);printf("▎|密 码：           |");
	Gotoxy(47,15);printf("▎********************");
	Gotoxy(56,12);scanf("%s",&zh0);
	Gotoxy(56,14);scanf("%s",&mm0);
	FILE *fp=fopen("数据\\admin.txt","r");
	fscanf(fp,"%s",&zh1);
	fscanf(fp,"%s",&mm1);
	fclose(fp);
	if(strcmp(zh0,zh1)==0&&strcmp(mm0,mm1)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void listInsert()   //录入成绩 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 录入成绩");//设置窗口标题
	system("CLS");	 
	int a,i,j;      //a为本次录入的人数 
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|要录入的个数：    |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(65,13);scanf("%d",&a);
	length=length+a;
	system("CLS");
	Gotoxy(33,2);printf("---------------------------------------------------");
	Gotoxy(33,3);printf("|         信息录入                                |");
	Gotoxy(33,4);printf("---------------------------------------------------");
	Gotoxy(33,5);printf("---------------------------------------------------"); 
	Gotoxy(33,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |");
	Gotoxy(33,7);printf("---------------------------------------------------");
	for(i=0;i<a;i++)
	{
		Gotoxy(33,2*i+8);printf("|         |         |         |         |         |");
		Gotoxy(33,2*i+9);printf("---------------------------------------------------");
	} 
	for(i=0;i<a;i++)
	{
		Gotoxy(35,2*i+8);scanf("%d",&L[i].num);
		Gotoxy(45,2*i+8);scanf("%s",&L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(55+10*j,2*i+8);scanf("%d",&L[i].score[j]);
		}
	} 
	system("CLS");
	HideCursor0();
	phone();
	Gotoxy(47,12);printf("▎*******************");
	Gotoxy(47,13);printf("▎|     录入成功    |");
	Gotoxy(47,14);printf("▎*******************");
	
	Sleep(700);	
	system("CLS");
}
void listInsert1()   //向已有成绩中添加学生 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 添加录入成绩");//设置窗口标题
	system("CLS");	 
	int i,j;
	system("CLS");
	Gotoxy(33,2);printf("---------------------------------------------------");
	Gotoxy(33,3);printf("|         添加录入成绩                             |");
	Gotoxy(33,4);printf("---------------------------------------------------");
	Gotoxy(33,5);printf("---------------------------------------------------"); 
	Gotoxy(33,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |");
	Gotoxy(33,7);printf("---------------------------------------------------");
	Gotoxy(33,8);printf("|         |         |         |         |         |");
	Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(35,8);scanf("%d",&L[length].num);
		Gotoxy(45,8);scanf("%s",&L[length].name);
		for(j=0;j<M;j++)
		{
			Gotoxy(55+10*j,8);scanf("%d",&L[length].score[j]);
		}
	length++;
	system("CLS");
	HideCursor0();
	Gotoxy(45,9);printf("************************");
	Gotoxy(45,10);printf("|                      |");
	Gotoxy(45,11);printf("|    添加录入成功！    |");
	Gotoxy(45,12);printf("|                      |");
	Gotoxy(45,13);printf("************************");
	Sleep(700);	
	system("CLS");
}
void gaiadmin()
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 修改密码");//设置窗口标题
	system("CLS");	 
	FILE *fp;
	char zh[30],mm[30],ymm[30],xmm[30];
	system("CLS");
	
	phone();
	Gotoxy(47,9);printf("▎***修改密码*********");
	Gotoxy(47,11);printf("▎********************");
	Gotoxy(47,12);printf("▎|原密码：          |");
	Gotoxy(47,13);printf("▎-------------------|");
	Gotoxy(47,14);printf("▎|新密码：          |");
	Gotoxy(47,15);printf("▎********************");
	Gotoxy(56,12);scanf("%s",ymm);
	Gotoxy(56,14);scanf("%s",xmm);
	fp = fopen("数据\\admin.txt","r");
	fscanf(fp,"%s",zh);
	fscanf(fp,"%s",mm);
	fclose(fp);
	if(strcmp(mm,ymm)==0)
	{
		fp = fopen("数据\\admin.txt","w");
		fprintf(fp,"%s\n",zh);
		fprintf(fp,"%s",xmm);
		fclose(fp);
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|     修改成功    |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700);
	}
	else
	{
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|     密码错误    |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700);
	}
}
void listDelet()    //删除成绩
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 删除成绩");//设置窗口标题
	system("CLS");	 
	int i,j;
	int num;
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|要删除的学号：    |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(63,13);scanf("%d",&num); 
	for(i=0;i<length;i++)
	{
		if(L[i].num==num)
			break;
	}
	HideCursor0();
	if(i!=length)
	{
		for(i;i<length-1;i++)
		{ 
			strcpy(L[i].name,L[i+1].name);
			L[i].num=L[i+1].num;
			for(j=0;j<3;j++)
			{
				L[i].score[j]=L[i+1].score[j];
			}
		}
		length--;
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|     删除成功    |");
		Gotoxy(47,14);printf("▎*******************");
	}
	else
	{
		
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|    没有该学生    |");
		Gotoxy(47,14);printf("▎*******************");
	}
	Sleep(700); 
} 
void listModify()   //更改成绩 
{
	system("CLS");	 
	int i,j;
	char name[30];
	system("CLS");
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|要更改的姓名：    |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(63,13);scanf("%s",&name);
	for(i=0;i<length;i++)
	{
		if(strcmp(L[i].name,name)==0)
			break;
	}
	if(i!=length)
	{
		system("CLS");
		Gotoxy(33,4);printf("---------------------------------------------------");
		Gotoxy(33,5);printf("|   信息更改                                      |");
		Gotoxy(33,6);printf("---------------------------------------------------");
		Gotoxy(33,7);printf("---------------------------------------------------"); 
		Gotoxy(33,8);printf("|  姓 名  |  学 号  |  语 文  |  数 学  |  英 语  |");
		Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(33,10);printf("|         |         |         |         |         |");
		Gotoxy(33,11);printf("---------------------------------------------------");
		Gotoxy(35,10);scanf("%s",&L[i].name);
		Gotoxy(45,10);scanf("%d",&L[i].num);
		for(j=0;j<M;j++)
		{
			Gotoxy(55+10*j,10);scanf("%d",&L[i].score[j]);
		}
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|     更改成功    |");
		Gotoxy(47,14);printf("▎*******************");
	}
	else
	{
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|    没有该学生    |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700); 
	}
	Sleep(700); 
} 
void listDisplay()   //查看所有成绩 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩 ->所有成绩");//设置窗口标题
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| 成绩单                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |  总 分  |  排 名  |");
	Gotoxy(26,7);printf("-----------------------------------------------------------------------");
	for(i=0;i<length;i++)
	{
		Gotoxy(26,2*i+8);printf("|         |         |         |         |         |         |         |");
		Gotoxy(26,2*i+9);printf("-----------------------------------------------------------------------");
	}
    listSort();
	for(i=0;i<length;i++)
	{
		Gotoxy(28,2*i+8);printf("%d",L[i].num);
		Gotoxy(38,2*i+8);printf("%s",L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(10*j+48,2*i+8);printf(" %d",L[i].score[j]);
		}
		Gotoxy(78,2*i+8);printf(" %d",L[i].sum);
		Gotoxy(88,2*i+8);printf(" %d",i+1);
		printf("\n");
	}
	getch();
} 

void listDisplay10()   //查看前多少成绩 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩 -> 前多少名的成绩");//设置窗口标题
	system("CLS");	 
	int a;
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|查看前多少名：    |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(63,13);scanf("%d",&a);
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩 -> 前a成绩");//设置窗口标题
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| 成绩单                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |  总 分  |  排 名  |");
	Gotoxy(26,7);printf("-----------------------------------------------------------------------");
	for(i=0;i<a;i++)
	{
		Gotoxy(26,2*i+8);printf("|         |         |         |         |         |         |         |");
		Gotoxy(26,2*i+9);printf("-----------------------------------------------------------------------");
	}
    listSort();
	for(i=0;i<a;i++)
	{
		Gotoxy(28,2*i+8);printf("%d",L[i].num);
		Gotoxy(38,2*i+8);printf("%s",L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(10*j+48,2*i+8);printf(" %d",L[i].score[j]);
		}
		Gotoxy(78,2*i+8);printf(" %d",L[i].sum);
		Gotoxy(88,2*i+8);printf(" %d",i+1);
		printf("\n");
	}
	getch();
} 

void listDisplayfu10()   //查看倒多少成绩 
{
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩 -> 倒数多少名的成绩");//设置窗口标题
	system("CLS");	 
	int a;
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|查看倒数多少名：  |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(65,13);scanf("%d",&a);
	SetConsoleTitle("主菜单 -> 管理登陆 -> 管理菜单 -> 查看成绩 -> 倒a成绩");//设置窗口标题
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| 成绩单                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |  总 分  | 倒数排名|");
	Gotoxy(26,7);printf("-----------------------------------------------------------------------");
	for(i=0;i<a+1;i++)
	{
		Gotoxy(26,2*i+7);printf("|         |         |         |         |         |         |         |");
		Gotoxy(26,2*i+8);printf("-----------------------------------------------------------------------");
	}
	for(i=0;i<=length;i++)
	{
		L[i].sum=0;
		for(j=0;j<3;j++)
		{
			L[i].sum=L[i].score[j]+L[i].sum;
		} 
	}
	for(i=0;i<length;i++)
	{
		for(j=0;j<length-i;j++)
			if(L[j].sum>L[j+1].sum)
			{
				t=L[j];
				L[j]=L[j+1];
				L[j+1]=t;
			}
	}
	for(i=1;i<=a;i++)
	{
		Gotoxy(28,2*i+7);printf("%d",L[i].num);
		Gotoxy(38,2*i+7);printf("%s",L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(10*j+48,2*i+7);printf(" %d",L[i].score[j]);
		}
		Gotoxy(78,2*i+7);printf(" %d",L[i].sum);
		Gotoxy(88,2*i+7);printf(" %d",i);
		printf("\n");
	}
	getch();
} 

void listSearch0()    //成绩查询  按姓名 
{
	SetConsoleTitle("主菜单 -> 成绩查询 -> 按姓名查询 ");//设置窗口标题
	system("CLS");	 
	char name[20];
	int i,j; 
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|要查询的姓名：    |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(65,13);scanf("%s",&name);
	for(i=0;i<length;i++)
	{
		if(strcmp(L[i].name,name)==0)
			break;
	}	
	HideCursor0();
	if(length!=i)
	{
		system("CLS");
		Gotoxy(33,2);printf("---------------------------------------------------");
		Gotoxy(33,3);printf("|        成绩查询>                                |");
		Gotoxy(51,3);printf("%s的成绩",L[i].name); 
		Gotoxy(33,4);printf("---------------------------------------------------");
		Gotoxy(33,5);printf("---------------------------------------------------"); 
		Gotoxy(33,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |");
		Gotoxy(33,7);printf("---------------------------------------------------");
		Gotoxy(33,8);printf("|         |         |         |         |         |");
		Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(33,10);printf("                                       -任意键继续-");
		Gotoxy(35,8);printf("%d",L[i].num); 
		Gotoxy(45,8);printf("%s",L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(55+10*j,8);printf("%d",L[i].score[j]);
		}
		Sleep(200);
		getch();
	}
	else
	{
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|    没有该学生   |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700); 
	}
} 
void listSearch1()    //成绩查询 按学号 
{
	SetConsoleTitle("主菜单 -> 成绩查询 -> 按学号查询 ");//设置窗口标题
	system("CLS");	 
	int i,j,num; 
	phone();
	Gotoxy(47,12);printf("▎********************");
	Gotoxy(47,13);printf("▎|要查询的学号 ：   |");
	Gotoxy(47,14);printf("▎********************");
	Gotoxy(65,13);scanf("%d",&num);
	for(i=0;i<length;i++)
	{
		if(L[i].num==num)
			break;
	}	
	HideCursor0();
	if(length!=i)
	{
		system("CLS");
		Gotoxy(33,2);printf("---------------------------------------------------");
		Gotoxy(33,3);printf("| 主菜单>成绩查询>                                |");
		Gotoxy(51,3);printf("%s的成绩",L[i].name); 
		Gotoxy(33,4);printf("---------------------------------------------------");
		Gotoxy(33,5);printf("---------------------------------------------------"); 
		Gotoxy(33,6);printf("|  学 号  |  姓 名  |  语 文  |  数 学  |  英 语  |");
		Gotoxy(33,7);printf("---------------------------------------------------");
		Gotoxy(33,8);printf("|         |         |         |         |         |");
		Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(33,10);printf("                                       -任意键继续-");
		Gotoxy(35,8);printf("%d",L[i].num); 
		Gotoxy(45,8);printf("%s",L[i].name);
		for(j=0;j<3;j++)
		{
			Gotoxy(55+10*j,8);printf("%d",L[i].score[j]);
		}
		Sleep(200);
		getch();
	}
	else
	{
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|    没有该学生    |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700); 
	}
} 

void  Quit()       //退出
{
	int color=0,i;
	SetConsoleTitle("学生管理系统退出中");//设置窗口标题 
	system("color 06");
	HideCursor0(); 
	for(i=0;i<67;i++)
	{
		DrawWord1(color);
		color=color+1;
		if(color==5)
			color=0;
		jindutiao1(i);
		Sleep(50);
	}
	system("color 03");
 } 
void paswordno()    //密码不正确界面
{
		system("CLS");
		phone();
		Gotoxy(47,12);printf("▎*******************");
		Gotoxy(47,13);printf("▎|  账号或密码错误 |");
		Gotoxy(47,14);printf("▎*******************");
		Sleep(700); 
} 
void about()
{
	SetConsoleTitle("主菜单 -> 关于");//设置窗口标题
	system("CLS");	
	Sleep(200); 
	phone();	
	Gotoxy(40,7);printf("       ▎*17数信1班三组* ");
	Gotoxy(40,9);printf("       ▎       赵志鹏");
	Gotoxy(40,10);printf("       ▎       史雅兴 ");
	Gotoxy(40,11);printf("       ▎       王方 ");
	Gotoxy(40,12);printf("       ▎       常昊月 ");
	Gotoxy(40,13);printf("       ▎       申玉璇 ");
	Gotoxy(40,14);printf("       ▎       高远");
	Gotoxy(40,15);printf("       ▎       杨旭");
	Gotoxy(40,16);printf("       ▎       谷薇 ");
	Gotoxy(40,17);printf("       ▎       王化 ");
	Gotoxy(40,18);printf("       ▎       段迎雪 ");
	Gotoxy(40,19);printf("       ▎       刘雪杰 ");
	Gotoxy(40,20);printf("       ▎       司婷婷 ");
	getch(); 
 } 
main()//
{
//	ShellExecuteA(NULL,TEXT("open"), TEXT("wmplayer.exe"), TEXT("数据//bgm.MP3"),NULL,SW_HIDE); 
	int y;
	int color=0,i;
	COORD pos={120,1000};//定义屏幕缓冲区大小的结构体 
	hout=GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄 
	system("mode con cols=120 lines=32");//设置窗口大小 宽120 高32 
	SetConsoleScreenBufferSize(hout,pos); //设置控制台缓冲区大小 
	SetConsoleTitle("17级一班三组学生管理系统");//设置窗口标题 
	HideCursor0(); 
	system("color 09");
	HideCursor0(); 
	for(i=0;i<67;i++)
	{
		DrawWord(color);
		color=color+1;
		if(color==5)
			color=0;
		jindutiao(i);
		Sleep(50);
	}
	
	system("CLS");
	listLoadN();      //读长度 
	if(length!=0)
	{
		listLoad();      //读文件  
	}
	system("mode con cols=32 lines=25");//设置窗口大小 宽32 高32 
	system("color 0f");
	phone1(); 
	Sleep(4000);
	system("mode con cols=120 lines=32");//设置窗口大小 宽32 高32 
	system("color b4");
C1:	HideCursor0();
	system("CLS");
	y=printMenu0();
	switch(y)
	{
		case 2:
				HideCursor1(); 
				y=admin(); 
				HideCursor0();
				if(y==1)
				{
				C2:	y=printMenu1();
					HideCursor1(); 
					switch(y)
					{
						case 2:
								HideCursor1(); 
								y=printMenu3();
								HideCursor0();
								if(y==2)
									listInsert();
								else if(y==3)
									listInsert1();	
								goto C2;break;    //录入 
							 
						case 3:listDelet();goto C2;break;    //删除 
						case 4:listModify();goto C2;break;   //更改 
						case 5:
							C4:	 HideCursor1(); //查看 
								y=printMenu4();
								HideCursor0();
								if(y==2)
									{
										listDisplay();
										system("CLS");
										goto C4;break;
									}
								else if(y==3)
								{
									listDisplay10();
									system("CLS");
									goto C4;break;
								}
								else if(y==4)
								{
									listDisplayfu10();
									system("CLS");
									goto C4;break;
								}									 
								else if(y==5)
								{
									goto C2;break; 
								}									
						case 6:gaiadmin();goto C2;break;        //改密 
						case 7:goto C1;break;               //退出 
					}break;
				}
				else
				{
					paswordno();goto C1;
				}
		case 3:
			C3:system("CLS");
				HideCursor0(); 
				y=printMenu2();
				HideCursor1(); 
				switch(y)
				{
					case 2:listDisplay();goto C3;break; 
					case 3:listSearch0();goto C3;break; 
					case 4:listSearch1();goto C3;break; 
					case 5:goto C1;break; 
				}break;
		case 4:about();goto C1;break;
		case 5:listSort(); 
				listSave();
				listSaveN();
				system("CLS");
				Sleep(700);
//				system("taskkill /f /im wmplayer.exe");
//				system("taskkill /f /im ConsolePauser.exe");
				Quit();
				system("taskkill /f /im ConsolePauser.exe");
				break;  
					
											    
	}

}



