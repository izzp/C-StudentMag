#include"stdio.h"
#include"windows.h"
#define  N  50 //ѧ������
#define M  3  //�γ̵�����


/* 
	18.1.25�����1.1�汾
	Dev-c++5.10����ͨ��
	0����0���� 
	������ȫ����� 
	��Ƚ�24�������0.91�汾����25�����1.0�����������޸��˼���С���� 
	ע�͵��˱������֣� 
	�����˳ɼ����ܣ��򿪴�����Ϣ���ļ��ǿ��������ɼ���
	���Բ鿴����ǰ������ ��
	���������xp���ã�win10��ʱ�㲻�ˣ� 
	�����˺ţ�admin���룺admin����¼����޸� 
	 
	ֻ��д��һ���ļ��������Ҫͨ���˳����˳� 
*/ 


typedef struct                               
{ 
	int num ;         /*ѧ��*/
	char name[20];   /*����*/
	int score[M];     /*���ſγɼ�*/
	int sum;        /*�ܷ�*/
   	int order;     /*����*/			
}Info; /*����ṹ������*/


Info  L[N];  /*����ṹ�����飬����ѧ����Ϣ�ĸ���*/

int length=0;  /*����ѧ����ʵ�ʸ���*/ 
 
HANDLE hout;
HWND h0ut;
int wzzt[2]={-1,-1};
CONSOLE_SCREEN_BUFFER_INFO	csbi;
WORD cols[] = {
	FOREGROUND_RED | FOREGROUND_INTENSITY, 		//��ɫ
	FOREGROUND_RED, 							//ǳ��ɫ
	FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, 	//��ɫ
	FOREGROUND_GREEN | FOREGROUND_INTENSITY,	//��ɫ
	FOREGROUND_BLUE | FOREGROUND_INTENSITY, 	//��ɫ
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

Gotoxy(int x,int y)//��λ���� 
{
    HANDLE h0ut;
    COORD pos={x,y};
    h0ut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h0ut,pos);
} 
void HideCursor0()//���ؿ���̨�Ĺ�� 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void HideCursor1()//��ʾ����̨�Ĺ�� 
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 1}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void shubiaoxy()
{
	POINT pt = { 0, 0 };
	h0ut = FindWindow("ConsoleWindowClass", NULL);// ����̨���
	HideCursor0();//���ؿ���̨�Ĺ��
	while (1)
	{
		if (GetKeyState(VK_LBUTTON) & 0x8000)
		{ 
			
			GetCursorPos(&pt);	//��ȡ��굱ǰλ��	
			ScreenToClient(h0ut, &pt);//��Դ���λ��
			wzzt[0] = pt.x;
			wzzt[1] = pt.y;
			break;
		}
	}
}
void phone()
{
	Gotoxy(47,3);printf("������������������������\n");
	Gotoxy(47,4);printf("��    ��     ----      ��\n");
	Gotoxy(47,5);printf("��-------------------- ��\n");
	Gotoxy(47,6);printf("��                     ��\n");
	Gotoxy(47,7);printf("��                     ��\n");
	Gotoxy(47,8);printf("��                     ��\n");
	Gotoxy(47,9);printf("��                     ��\n");
	Gotoxy(47,10);printf("��                     ��\n");
	Gotoxy(47,11);printf("��                     ��\n");
	Gotoxy(47,12);printf("��                     ��\n");
	Gotoxy(47,13);printf("��                     ��\n");
	Gotoxy(47,14);printf("��                     ��\n");
	Gotoxy(47,15);printf("��                     ��\n");
	Gotoxy(47,16);printf("��                     ��\n");
	Gotoxy(47,17);printf("��                     ��\n");
	Gotoxy(47,18);printf("��                     ��\n");
	Gotoxy(47,19);printf("��                     ��\n");
	Gotoxy(47,20);printf("��                     ��\n");
	Gotoxy(47,21);printf("��                     ��\n");
	Gotoxy(47,22);printf("��                     ��\n");
	Gotoxy(47,23);printf("���x�x�x�x�x�x�x�x�x�x ��\n");
	Gotoxy(47,24);printf("��         ��          ��\n");
	Gotoxy(47,25);printf("���y�y�y�y�y�y�y�y�y�y��");
}
void phone1()
{
	Gotoxy(47,3);printf("������������������������\n");
	Gotoxy(47,4);printf("��    ��     ----      ��\n");
	Gotoxy(47,5);printf("��-------------------- ��\n");
	Gotoxy(47,6);printf("��                     ��\n");
	Gotoxy(47,7);printf("��                     ��\n");
	Gotoxy(47,8);printf("��                     ��\n");
	Gotoxy(47,9);printf("��                     ��\n");
	Gotoxy(47,10);printf("��             .:'     ��\n");
	Gotoxy(47,11);printf("��        __ :'__      ��\n");
	Gotoxy(47,12);printf("��    .'`   `-' ``.    ��\n");
	Gotoxy(47,13);printf("��   :          .-'    ��\n");
	Gotoxy(47,14);printf("��   :          :      ��\n");
	Gotoxy(47,15);printf("��   :          `-;    ��\n");
	Gotoxy(47,16);printf("��    `. __.-.__ .     ��\n");
	Gotoxy(47,17);printf("��                     ��\n");
	Gotoxy(47,18);printf("��                     ��\n");
	Gotoxy(47,19);printf("��                     ��\n");
	Gotoxy(47,20);printf("��                     ��\n");
	Gotoxy(47,21);printf("��                     ��\n");
	Gotoxy(47,22);printf("��                     ��\n");
	Gotoxy(47,23);printf("���x�x�x�x�x�x�x�x�x�x ��\n");
	Gotoxy(47,24);printf("��         ��          ��\n");
	Gotoxy(47,25);printf("���y�y�y�y�y�y�y�y�y�y��");
}
void DrawWord(int color)
{
	int row, col, cut;//�У��У�����
	COORD pos;		//���꣬���ڹ��Ķ�λ
	DWORD dwLen;	//�޷�������
	color=color/2;
	for(cut = 0; cut < 7; cut++)	//�����ַ�����ѭ��
	{
		for(row = 0; row < 8; row++)	//ÿ�ַ�8��
		{
			//�ѹ�궨λ�����е�����λ��
			pos.X = cut * 10+25;
			pos.Y = row+7;
			SetConsoleCursorPosition(hout, pos);	//�ѹ�궨λ��posָ����λ��
			for(col = 0; col < 9; col++)	//ÿ�ַ�9��
			{
				if(letter[cut][row][col] == 1)
				{
					GetConsoleScreenBufferInfo(hout, &csbi);
					printf("*");
					//��ɫ
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
	Gotoxy(50+i,17);printf("���������� ");
}

void DrawWord1(int color)
{
	int row, col, cut;//�У��У�����
	COORD pos;		//���꣬���ڹ��Ķ�λ
	DWORD dwLen;	//�޷�������
	color=color/2;
	for(cut = 0; cut < 7; cut++)	//�����ַ�����ѭ��
	{
		for(row = 0; row < 8; row++)	//ÿ�ַ�8��
		{
			//�ѹ�궨λ�����е�����λ��
			pos.X = cut * 10+25;
			pos.Y = row+7;
			SetConsoleCursorPosition(hout, pos);	//�ѹ�궨λ��posָ����λ��
			for(col = 0; col < 9; col++)	//ÿ�ַ�9��
			{
				if(letter1[cut][row][col] == 1)
				{
					GetConsoleScreenBufferInfo(hout, &csbi);
					printf("*");
					//��ɫ
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
	printf("�� �� �� �� ��:                              ");
	Gotoxy(49,18);
	printf("---------------------------------");
	i=i%22;
	Gotoxy(50+i,17);printf("���������� ");
}
void listSaveN()    //������ĳ���lengthֵ���浽D:\num.txt�ļ��С�
{
	FILE *f;
	int i;
	f=fopen("����\\num.txt","w");
	if(f==0)
	printf("���ļ�\n");
	fprintf(f,"%d",length); 
	fclose(f);	
} 
void listLoadN()    //���ļ���Ԫ�صĸ�������length�С�
{
	FILE *f;
	int i;
	f=fopen("����\\num.txt","r");
	if(f==0)
	printf("���ļ�\n");
	fscanf(f,"%d",&length);
	fclose(f);
}
void listSort()     //���� ������� 
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

void listLoad() //��
{
	int i,j;
	FILE *fp;
	fp=fopen("����\\chengji.txt","r");	
	if(fp==NULL)
	{
		printf("���ܴ򿪸��ļ�\n");
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
void listSave()  //д 
{
	int i,j;
	FILE *fp;
	fp=fopen("����\\chengji.txt","w");
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

int printMenu0()//���˵� 
{
	SetConsoleTitle("���˵�");//���ô��ڱ��� 
	Sleep(200); 
    phone();		
	do
	{
	Gotoxy(40,8);printf("       ��  ���˵�");
	Gotoxy(40,11);printf("       ��     �������¼��");
	Gotoxy(40,13);printf("       ��     ���ɼ���ѯ��");
	Gotoxy(40,15);printf("       ��     ��  ����  ��");
	Gotoxy(40,17);printf("       ��     ��  �˳�  ��"); 	
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
int printMenu1() //����Ա�˵� 
{
	
	SetConsoleTitle("���˵� -> �����½ -> ����˵�");//���ô��ڱ���
	system("CLS");	
	Sleep(200); 
	phone();	
	do
	{
	Gotoxy(40,8);printf("       ��*����˵�* ");
	Gotoxy(40,11);printf("       ��    ��¼��ɼ���");
	Gotoxy(40,13);printf("       ��    ��ɾ���ɼ���");
	Gotoxy(40,15);printf("       ��    �����ĳɼ��� ");
	Gotoxy(40,17);printf("       ��    ���鿴�ɼ��� ");
	Gotoxy(40,19);printf("       ��    ���޸����롹 ");
	Gotoxy(40,21);printf("       ��    �������ϲ㡹 "); 
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
int printMenu2()  //�ɼ���ѯ�˵� 
{
	Sleep(200); 
	SetConsoleTitle("���˵� -> �ɼ���ѯ");//���ô��ڱ��� 
	phone();	
	do
	{
		Gotoxy(40,8);printf("       ���ɼ���ѯ");
		Gotoxy(40,11);printf("       ��    ���ɼ�����ѯ�� ");
		Gotoxy(40,13);printf("       ��    ����������ѯ�� ");
		Gotoxy(40,15);printf("       ��    ����ѧ�Ų�ѯ�� ");
		Gotoxy(40,17);printf("       ��    ������  �ϲ㡹 "); 
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
int printMenu3()//¼��ѡ��˵� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> ¼��ѡ��˵�");//���ô��ڱ���
	Sleep(200); 
    phone();		
	do
	{
		Gotoxy(40,8);printf("       �� ¼��ѡ��˵�");
		Gotoxy(40,11);printf("       ��    ���״�¼�롹");
		Gotoxy(40,13);printf("       ��    �����ѧ����");
	
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
int printMenu4()//�鿴�ɼ��˵� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ�");//���ô��ڱ���
	Sleep(200); 
    phone();		
	do
	{
	Gotoxy(40,8);printf("       ��  �鿴�ɼ�");
	Gotoxy(40,11);printf("       ��     �����гɼ���");
	Gotoxy(40,13);printf("       ��     �����ǰ����");
	Gotoxy(40,15);printf("       ��     �����������");
	Gotoxy(40,17);printf("       ��     �������ϼ���"); 	
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
int admin()		 //����Ա��½ 
{
	
	SetConsoleTitle("���˵� -> �����½");//���ô��ڱ��� 
	system("CLS");	 
	char zh0[30],zh1[30],mm0[30],mm1[30];	
	phone();
	Gotoxy(47,9);printf("��***�����½*********");
	Gotoxy(47,11);printf("��********************");
	Gotoxy(47,12);printf("��|�� �ţ�           |");
	Gotoxy(47,13);printf("��-------------------|");
	Gotoxy(47,14);printf("��|�� �룺           |");
	Gotoxy(47,15);printf("��********************");
	Gotoxy(56,12);scanf("%s",&zh0);
	Gotoxy(56,14);scanf("%s",&mm0);
	FILE *fp=fopen("����\\admin.txt","r");
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

void listInsert()   //¼��ɼ� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> ¼��ɼ�");//���ô��ڱ���
	system("CLS");	 
	int a,i,j;      //aΪ����¼������� 
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|Ҫ¼��ĸ�����    |");
	Gotoxy(47,14);printf("��********************");
	Gotoxy(65,13);scanf("%d",&a);
	length=length+a;
	system("CLS");
	Gotoxy(33,2);printf("---------------------------------------------------");
	Gotoxy(33,3);printf("|         ��Ϣ¼��                                |");
	Gotoxy(33,4);printf("---------------------------------------------------");
	Gotoxy(33,5);printf("---------------------------------------------------"); 
	Gotoxy(33,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |");
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
	Gotoxy(47,12);printf("��*******************");
	Gotoxy(47,13);printf("��|     ¼��ɹ�    |");
	Gotoxy(47,14);printf("��*******************");
	
	Sleep(700);	
	system("CLS");
}
void listInsert1()   //�����гɼ������ѧ�� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> ���¼��ɼ�");//���ô��ڱ���
	system("CLS");	 
	int i,j;
	system("CLS");
	Gotoxy(33,2);printf("---------------------------------------------------");
	Gotoxy(33,3);printf("|         ���¼��ɼ�                             |");
	Gotoxy(33,4);printf("---------------------------------------------------");
	Gotoxy(33,5);printf("---------------------------------------------------"); 
	Gotoxy(33,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |");
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
	Gotoxy(45,11);printf("|    ���¼��ɹ���    |");
	Gotoxy(45,12);printf("|                      |");
	Gotoxy(45,13);printf("************************");
	Sleep(700);	
	system("CLS");
}
void gaiadmin()
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �޸�����");//���ô��ڱ���
	system("CLS");	 
	FILE *fp;
	char zh[30],mm[30],ymm[30],xmm[30];
	system("CLS");
	
	phone();
	Gotoxy(47,9);printf("��***�޸�����*********");
	Gotoxy(47,11);printf("��********************");
	Gotoxy(47,12);printf("��|ԭ���룺          |");
	Gotoxy(47,13);printf("��-------------------|");
	Gotoxy(47,14);printf("��|�����룺          |");
	Gotoxy(47,15);printf("��********************");
	Gotoxy(56,12);scanf("%s",ymm);
	Gotoxy(56,14);scanf("%s",xmm);
	fp = fopen("����\\admin.txt","r");
	fscanf(fp,"%s",zh);
	fscanf(fp,"%s",mm);
	fclose(fp);
	if(strcmp(mm,ymm)==0)
	{
		fp = fopen("����\\admin.txt","w");
		fprintf(fp,"%s\n",zh);
		fprintf(fp,"%s",xmm);
		fclose(fp);
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|     �޸ĳɹ�    |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700);
	}
	else
	{
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|     �������    |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700);
	}
}
void listDelet()    //ɾ���ɼ�
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> ɾ���ɼ�");//���ô��ڱ���
	system("CLS");	 
	int i,j;
	int num;
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|Ҫɾ����ѧ�ţ�    |");
	Gotoxy(47,14);printf("��********************");
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
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|     ɾ���ɹ�    |");
		Gotoxy(47,14);printf("��*******************");
	}
	else
	{
		
		system("CLS");
		phone();
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|    û�и�ѧ��    |");
		Gotoxy(47,14);printf("��*******************");
	}
	Sleep(700); 
} 
void listModify()   //���ĳɼ� 
{
	system("CLS");	 
	int i,j;
	char name[30];
	system("CLS");
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|Ҫ���ĵ�������    |");
	Gotoxy(47,14);printf("��********************");
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
		Gotoxy(33,5);printf("|   ��Ϣ����                                      |");
		Gotoxy(33,6);printf("---------------------------------------------------");
		Gotoxy(33,7);printf("---------------------------------------------------"); 
		Gotoxy(33,8);printf("|  �� ��  |  ѧ ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |");
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
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|     ���ĳɹ�    |");
		Gotoxy(47,14);printf("��*******************");
	}
	else
	{
		HideCursor0();
		system("CLS");
		phone();
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|    û�и�ѧ��    |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700); 
	}
	Sleep(700); 
} 
void listDisplay()   //�鿴���гɼ� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ� ->���гɼ�");//���ô��ڱ���
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| �ɼ���                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |  �� ��  |  �� ��  |");
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

void listDisplay10()   //�鿴ǰ���ٳɼ� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ� -> ǰ�������ĳɼ�");//���ô��ڱ���
	system("CLS");	 
	int a;
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|�鿴ǰ��������    |");
	Gotoxy(47,14);printf("��********************");
	Gotoxy(63,13);scanf("%d",&a);
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ� -> ǰa�ɼ�");//���ô��ڱ���
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| �ɼ���                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |  �� ��  |  �� ��  |");
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

void listDisplayfu10()   //�鿴�����ٳɼ� 
{
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ� -> �����������ĳɼ�");//���ô��ڱ���
	system("CLS");	 
	int a;
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|�鿴������������  |");
	Gotoxy(47,14);printf("��********************");
	Gotoxy(65,13);scanf("%d",&a);
	SetConsoleTitle("���˵� -> �����½ -> ����˵� -> �鿴�ɼ� -> ��a�ɼ�");//���ô��ڱ���
	system("CLS");	 
	int i=0,j=0;
	Info t;
	system("CLS");
	Gotoxy(26,2);printf("-----------------------------------------------------------------------");
	Gotoxy(26,3);printf("| �ɼ���                                                   -----      |");
	Gotoxy(26,4);printf("-----------------------------------------------------------------------");
	Gotoxy(26,5);printf("-----------------------------------------------------------------------"); 
	Gotoxy(26,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |  �� ��  | ��������|");
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

void listSearch0()    //�ɼ���ѯ  ������ 
{
	SetConsoleTitle("���˵� -> �ɼ���ѯ -> ��������ѯ ");//���ô��ڱ���
	system("CLS");	 
	char name[20];
	int i,j; 
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|Ҫ��ѯ��������    |");
	Gotoxy(47,14);printf("��********************");
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
		Gotoxy(33,3);printf("|        �ɼ���ѯ>                                |");
		Gotoxy(51,3);printf("%s�ĳɼ�",L[i].name); 
		Gotoxy(33,4);printf("---------------------------------------------------");
		Gotoxy(33,5);printf("---------------------------------------------------"); 
		Gotoxy(33,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |");
		Gotoxy(33,7);printf("---------------------------------------------------");
		Gotoxy(33,8);printf("|         |         |         |         |         |");
		Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(33,10);printf("                                       -���������-");
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
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|    û�и�ѧ��   |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700); 
	}
} 
void listSearch1()    //�ɼ���ѯ ��ѧ�� 
{
	SetConsoleTitle("���˵� -> �ɼ���ѯ -> ��ѧ�Ų�ѯ ");//���ô��ڱ���
	system("CLS");	 
	int i,j,num; 
	phone();
	Gotoxy(47,12);printf("��********************");
	Gotoxy(47,13);printf("��|Ҫ��ѯ��ѧ�� ��   |");
	Gotoxy(47,14);printf("��********************");
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
		Gotoxy(33,3);printf("| ���˵�>�ɼ���ѯ>                                |");
		Gotoxy(51,3);printf("%s�ĳɼ�",L[i].name); 
		Gotoxy(33,4);printf("---------------------------------------------------");
		Gotoxy(33,5);printf("---------------------------------------------------"); 
		Gotoxy(33,6);printf("|  ѧ ��  |  �� ��  |  �� ��  |  �� ѧ  |  Ӣ ��  |");
		Gotoxy(33,7);printf("---------------------------------------------------");
		Gotoxy(33,8);printf("|         |         |         |         |         |");
		Gotoxy(33,9);printf("---------------------------------------------------");
		Gotoxy(33,10);printf("                                       -���������-");
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
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|    û�и�ѧ��    |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700); 
	}
} 

void  Quit()       //�˳�
{
	int color=0,i;
	SetConsoleTitle("ѧ������ϵͳ�˳���");//���ô��ڱ��� 
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
void paswordno()    //���벻��ȷ����
{
		system("CLS");
		phone();
		Gotoxy(47,12);printf("��*******************");
		Gotoxy(47,13);printf("��|  �˺Ż�������� |");
		Gotoxy(47,14);printf("��*******************");
		Sleep(700); 
} 
void about()
{
	SetConsoleTitle("���˵� -> ����");//���ô��ڱ���
	system("CLS");	
	Sleep(200); 
	phone();	
	Gotoxy(40,7);printf("       ��*17����1������* ");
	Gotoxy(40,9);printf("       ��       ��־��");
	Gotoxy(40,10);printf("       ��       ʷ���� ");
	Gotoxy(40,11);printf("       ��       ���� ");
	Gotoxy(40,12);printf("       ��       ����� ");
	Gotoxy(40,13);printf("       ��       ����� ");
	Gotoxy(40,14);printf("       ��       ��Զ");
	Gotoxy(40,15);printf("       ��       ����");
	Gotoxy(40,16);printf("       ��       ��ޱ ");
	Gotoxy(40,17);printf("       ��       ���� ");
	Gotoxy(40,18);printf("       ��       ��ӭѩ ");
	Gotoxy(40,19);printf("       ��       ��ѩ�� ");
	Gotoxy(40,20);printf("       ��       ˾���� ");
	getch(); 
 } 
main()//
{
//	ShellExecuteA(NULL,TEXT("open"), TEXT("wmplayer.exe"), TEXT("����//bgm.MP3"),NULL,SW_HIDE); 
	int y;
	int color=0,i;
	COORD pos={120,1000};//������Ļ��������С�Ľṹ�� 
	hout=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨��� 
	system("mode con cols=120 lines=32");//���ô��ڴ�С ��120 ��32 
	SetConsoleScreenBufferSize(hout,pos); //���ÿ���̨��������С 
	SetConsoleTitle("17��һ������ѧ������ϵͳ");//���ô��ڱ��� 
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
	listLoadN();      //������ 
	if(length!=0)
	{
		listLoad();      //���ļ�  
	}
	system("mode con cols=32 lines=25");//���ô��ڴ�С ��32 ��32 
	system("color 0f");
	phone1(); 
	Sleep(4000);
	system("mode con cols=120 lines=32");//���ô��ڴ�С ��32 ��32 
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
								goto C2;break;    //¼�� 
							 
						case 3:listDelet();goto C2;break;    //ɾ�� 
						case 4:listModify();goto C2;break;   //���� 
						case 5:
							C4:	 HideCursor1(); //�鿴 
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
						case 6:gaiadmin();goto C2;break;        //���� 
						case 7:goto C1;break;               //�˳� 
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



