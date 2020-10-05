#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN=300010; 

int n,k;//n��Ԫ�أ�m������ 

struct node{
    int l,r,v,lazy;
}tree[4*MAXN+1];//��ʵ���ٿ���4*MAXN���� 

void build(int l,int r,int k){//��ǰ�ڵ�洢���߶ε����Ҷ˵�&����ڵ�ı�� 
    tree[k].l=l;tree[k].r=r;
    if(l==r){
        tree[k].v = 0;//Ҷ�ӽڵ��ֵ����������룡 
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,k*2);
    build(mid+1,r,k*2+1);
    tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

//�·�lazy��Ǻ���
void putdown(int k){
    tree[k*2].lazy+=tree[k].lazy;
    tree[k*2+1].lazy+=tree[k].lazy;
    tree[k*2].v+=tree[k].lazy*(tree[k*2].r-tree[k*2].l+1);//�ӵ㣺1.Ҫ�ø��ڵ�k��lazy  2.���䳤�ȼǵ�Ҫ+1//
    tree[k*2+1].v+=tree[k].lazy*(tree[k*2+1].r-tree[k*2+1].l+1);//�ӵ㣺ͬ��//
    tree[k].lazy=0;//�ӵ㣺���ڵ��lazyҪ��0����������// 
} 

//�����ѯ��Ҷ�ӽڵ㣩 
int askpoint(int x,int k){
    if(tree[k].l==tree[k].r){
        return tree[k].v;
    }
    if(tree[k].lazy)putdown(k);//��ֹ�ظ��·� 
    int mid=(tree[k].l+tree[k].r)/2;
    if(x<=mid)return askpoint(x,k*2);
    else return askpoint(x,k*2+1);
}

//�����޸� 
void changesection(int tl,int tr,int num,int k){
    if(tl<=tree[k].l&&tr>=tree[k].r){//�Բ�ѯ���� 
        tree[k].v+=num*(tree[k].r-tree[k].l+1);//�ӵ�// 
        tree[k].lazy+=num; 
        return;
    }
    if(tree[k].lazy)putdown(k);//��ֹ�ظ��·� 
    int mid=(tree[k].r+tree[k].l)/2;//��� //
    if(tl<=mid)changesection(tl,tr,num,k*2);
    if(tr>mid)changesection(tl,tr,num,k*2+1);
    tree[k].v=tree[k*2].v+tree[k*2+1].v;
}

//�����ѯ 
int sum=0;
void asksec(int tl,int tr,int l,int r,int k){
    if(l>=tl&&r<=tr){
        sum+=tree[k].v;
        return;
    }
    if(tree[k].lazy)putdown(k);//��ֹ�ظ��·� 
    int mid=(tree[k].r+tree[k].l)/2;
    if(tl<=mid)asksec(tl,tr,l,mid,k*2);
    if(tr>mid)asksec(tl,tr,mid+1,r,k*2+1);
}

int main(){
    //freopen("in.in","r",stdin);
    //cout<<"����"<<endl;
    scanf("%d%d",&n,&k);
    //cout<<"build tree"<<endl; 
    build(1,300010,1);
    //cout<<"change section"<<endl; 
    int x,y,num;
    REP(i,1,n){
    	scanf("%d%d",&x,&y);
    	changesection(x,y,1,1);
	}
    //cout<<"ask point"<<endl;
    scanf("%d",&x);
    printf("%d\n",askpoint(x,1));
    cout<<"ask section"<<endl;
    int tl,tr;
    scanf("%d%d",&tl,&tr);
    asksec(tl,tr,1,n,1);
    printf("%d\n",sum);
    return 0;
}
