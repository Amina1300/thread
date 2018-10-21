#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int start=0;
int end=100;
int total;
int a[1000];

void * sum_(void *arg)
{
	int j;
total=0;
int start=(int*)arg;
for( j=start;j<end;j++)
total=total+a[j];

end=end+100;
return ((void*)total);
}
int main(){
int sum=0;
int fsum1,fsum2,fsum3,fsum4,fsum5,fsum6,fsum7,fsum8,fsum9,fsum10=0;
pthread_t  _thread1,_thread2,_thread3,_thread4,_thread5,_thread6,_thread7,_thread8,_thread9,_thread10;
int i;
for( i=0;i<1000;i++)
a[i]=i+1;

pthread_create(&_thread1,(NULL),sum_,(void*)0);
pthread_create(&_thread2,(NULL),sum_,(void*)100);
pthread_create(&_thread3,(NULL),sum_,(void*)200);
pthread_create(&_thread4,(NULL),sum_,(void*)300);
pthread_create(&_thread5,(NULL),sum_,(void*)400);
pthread_create(&_thread6,(NULL),sum_,(void*)500);
pthread_create(&_thread7,(NULL),sum_,(void*)600);
pthread_create(&_thread8,(NULL),sum_,(void*)700);
pthread_create(&_thread9,(NULL),sum_,(void*)800);
pthread_create(&_thread10,(NULL),sum_,(void*)900);

pthread_join(_thread1,(void**)&fsum1);
pthread_join(_thread2,(void**)&fsum2);
pthread_join(_thread3,(void**)&fsum3);
pthread_join(_thread4,(void**)&fsum4);
pthread_join(_thread5,(void**)&fsum5);
pthread_join(_thread6,(void**)&fsum6);
pthread_join(_thread7,(void**)&fsum7);
pthread_join(_thread8,(void**)&fsum8);
pthread_join(_thread9,(void**)&fsum9);
pthread_join(_thread10,(void**)&fsum10);
sum=fsum1+fsum2+fsum3+fsum4+fsum5+fsum6+fsum7+fsum8+fsum9+fsum10;



printf("SUm is %d",sum);
system("pause");
return 0;
}
