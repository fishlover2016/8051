#include <REG_MPC82G516.h>

//Global variables and definition
int seed=101;

int pad[6]={31,143,199,227,241,248};
int bullet[6]={95,175,215,235,245,250};
int num[4]={0,0,0,0};
int start=2;
int count=0;
int press=0;
int gun=0;
int pos3=0;
int pos4=0;
int go=0;
int win=0;

int a[8]={0,0,0,0,0,0,0,0};
int b[8]={0,0,0,0,0,0,0,0};


void delay(int t){
	int i;
	while(t--)
		for(i=0;i<100;++i);
}

void ini()
{
	
	int nodo=0;
	int c1=0;
	
	num[0]=0;
	num[1]=0;
	num[2]=0;
	num[3]=0;
	start=2;
	count=0;
	press=0;
	gun=0;
	pos3=0;
	pos4=0;
	go=0;
	win=0;
	
	while(1)
	{
		
		P0=num[1];
		P10=0;
		delay(5);
		P10=1;
			
		P0=num[0];
		P11=0;
		delay(5);
		P11=1;
		
		if(nodo==1)
		{
			c1++;
			if(c1>=50)
			{
				nodo=0;
				c1=0;
			}
		}
		
		
		if(P24==0&&nodo==0)
		{
			if(num[1]==9&&num[0]==9)
			{
				
			}
			else if(num[1]==9&&num[0]!=9)
			{
				num[1]=0;
				num[0]++;
			}
			else if(num[1]!=9)
			{
				num[1]++;
			}
			
			nodo=1;
		}
		
		if(P25==0&&nodo==0)
		{
			if(num[1]==0&&num[0]==0)
			{
				
			}
			else if(num[1]==0&&num[0]!=0)
			{
				num[1]=9;
				num[0]--;
			}
			else if(num[1]!=0)
			{
				num[1]--;
			}
			
			nodo=1;
		}
		
		if(P27==0&&(num[1]+num[0])>0)
		{
			return;
		}
		
	}
	
	
	
}




void decrease()
{
	if(num[3]==0)
	{
		if(num[2]!=0)
		{
			num[3]=9;
			num[2]=num[2]-1;
		}
	}
	else
	{
		num[3]=num[3]-1;
	}
}

void hit(int pos)
{
	
			if(pos==5)
			{
				if(a[0]==0)
				{
				decrease();
				}
				if(a[2]==0)
				{
				decrease();
				}
				a[0]=1;
				a[2]=1;
			}
			else if(pos==4)
			{
				if(a[1]==0)
				{
				decrease();
				}
				if(a[3]==0)
				{
				decrease();
				}
				a[1]=1;
				a[3]=1;
			}
			else if(pos==3)
			{
				if(a[2]==0)
				{
				decrease();
				}
				if(a[4]==0)
				{
				decrease();
				}
				a[2]=1;
				a[4]=1;
			}
			else if(pos==2)
			{
				if(a[3]==0)
				{
				decrease();
				}
				if(a[5]==0)
				{
				decrease();
				}
				a[3]=1;
				a[5]=1;
			}
			else if(pos==1)
			{
				if(a[4]==0)
				{
				decrease();
				}
				if(a[6]==0)
				{
				decrease();
				}
				a[4]=1;
				a[6]=1;
			}
			else if(pos==0)
			{
				if(a[5]==0)
				{
				decrease();
				}
				if(a[7]==0)
				{
				decrease();
				}
				a[5]=1;
				a[7]=1;
			}
			
			
	
}


void display(int pos1,int data2){
	
	int i,i2;
	
	
	for(i2=0;i2<=15;i2++)
	{
		
		
		
		for(i=0;i<75;++i)
		{
			
			//enemy
			P2=pos1;
			P30=a[0];
			P31=a[1];
			P32=a[2];
			P33=a[3];
			P34=a[4];
			P35=a[5];
			P36=a[6];
			P37=a[7];
			delay(10);
			P3=255;
			
			
			
			//pad
			P2=15;
			P3=data2;
			delay(10);
			P3=255;
			
			
			if(i2==15)
			{
				win=2;
				return;
			}
			
			if(gun==1)
			{
				pos3=start;  //pad position
				pos4=14;     //from bottom
				go=1;
				gun=0;
			}
			
			if(go==1)
			{
				
				if(pos4==pos1)
				{
					go=0;
					hit(pos3);
				}
				
				
				P2=pos4;
				P3=bullet[pos3];
				pos4--;
				delay(10);
				P3=255;
				
				
			}
			
			P2=255;
		
			P0=num[3];
			P10=0;
			delay(10);
			P10=1;
			
			P0=num[2];
			P11=0;
			delay(10);
			P11=1;
			
			P0=num[1];
			P12=0;
			delay(10);
			P12=1;
			
			P0=num[0];
			P13=0;
			delay(10);
			P13=1;
			
			if(press==1&&count<8)
			{
				count++;
			}
			else
			{
				count=0;
				press=0;
			}
			
			if(P24==0&&start<5&&count==0)
			{
				press=1;
				start++;
				data2=pad[start];
				
			}
			
			if(P26==0&&start>0&&count==0)
			{
				press=1;
				start--;
				data2=pad[start];
				
			}
			
			if(P25==0&&gun==0)
			{
				gun=1;
			}
			
		}
		
		
		if(pos4==pos1&&go==1)
		{
			go=0;
			hit(pos3);
		}
		
		pos1++;
		
		if(num[2]==0&&num[3]==0)
		{
			
			break;
			
		}
		
		
	}
	
}




void clear()
{
	int i=0;
	
	for(i=0;i<=15;i++)
	{
		P2=i;
		P30=0;
		P31=0;
		P32=0;
		P33=0;
		P34=0;
		P35=0;
		P36=0;
		P37=0;
		delay(500);
		P3=255;
	}
	
	
	
}


/*     RANDOM      */

int rand()
{
	
	
	seed=seed+1531;
	if(seed>100000)
	{
		seed=seed-99997;
	}
	
	if(seed<0)
	{
		seed=713;
	}
	
	if(seed==0)
	{
		seed=seed+39*17;
	}
	
	return (seed%8)+1;
	
}


void set(int n1)
{
	
	a[0]=1;
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[4]=1;
	a[5]=1;
	a[6]=1;
	a[7]=1;
	
	if(n1==1)
	{
		a[2]=0;
	}
	else if(n1==2)
	{
		a[2]=0;
		a[4]=0;
	}
	else if(n1==3)
	{
		a[2]=0;
		a[4]=0;
		a[5]=0;
	}
	else if(n1==4)
	{
		a[0]=0;
		a[3]=0;
		a[4]=0;
		a[6]=0;
	}
	else if(n1==5)
	{
		a[0]=0;
		a[2]=0;
		a[4]=0;
		a[5]=0;
		a[6]=0;
	}
	else if(n1==6)
	{
		a[0]=0;
		a[2]=0;
		a[3]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
	}
	else if(n1==7)
	{
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		a[6]=0;
		a[7]=0;
	}
	else if(n1==8)
	{
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
	}
	
}


void msg(int col,int msgdata)
{
	int i=100;
	P2=col;
	P3=msgdata;
	here:
	if(i!=0)
	{
		i--;
		goto here;
	}
	
	P3=255;
}


void infloop()
{
	
	
	while(1)
	{
		
		if(win==2)
		{
			msg(0,0);
			msg(1,127);
			msg(2,127);
			msg(3,129);
			msg(4,126);
			msg(5,126);
			msg(6,129);
			msg(7,255);
			msg(8,185);
			msg(9,118);
			msg(10,118);
			msg(11,141);
			msg(12,255);
			msg(13,0);
			msg(14,118);
			msg(15,118);
			
			
		}
		
		if(win==0)
		{
			msg(0,0);
			msg(1,159);
			msg(2,239);
			msg(3,159);
			msg(4,0);
			msg(5,255);
			msg(6,126);
			msg(7,0);
			msg(8,126);
			msg(9,255);
			msg(10,0);
			msg(11,253);
			msg(12,243);
			msg(13,207);
			msg(14,191);
			msg(15,0);
		}
		
		
		P2=255;
		
		if(P27==0)
		{
			break;
		}
	}
}

void main()
{

	
	int i=0;
	int enemy=0;
	
	int temp1=0;
	
	while(1)
	{
	
	enemy=rand();
	ini();
	
	start:
	
	
	enemy=rand();
	while(enemy>(num[0]*10+num[1])||enemy<=0)
	{
		enemy=rand();
		
	}
	set(enemy);
	
	
	
	num[2]=enemy/10;
	num[3]=enemy%10;
	
	temp1=num[0]*10+num[1]-enemy;
	num[1]=temp1%10;
	num[0]=temp1/10;
	
	display(0,pad[start]);
	
	if(win==2)
	{
		goto fail;
	}
	
	if((num[0]*10+num[1])>0)
	{
		goto start;
	}
	
	
	
	fail:
	clear();
	
	infloop();
	
	
	}
	
	


}
