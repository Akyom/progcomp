#include <stdio.h>
#include <string.h>

typedef struct{
	int dir;
	int bend;
	int ori[4];
}wp;

// DIR:
// +x=1
// -x=-1
// +y=2
// -y=-2
// +z=3
// -z=-3

// BEND:
// no=0
// up=1
// down=2
// right=3
// left =4

// ORI:
/*  0
  1   3
    2  */
/*
int changedir(wp wire[i], wp wire[i+1]){
	switch(wire[i].bend){
		case 0:
			wire[i+1].dir=wire[i].dir;
			wire[i+1].ori[0]=wire[i].ori[0];
			wire[i+1].ori[1]=wire[i].ori[1];
			wire[i+1].ori[2]=wire[i].ori[2];
			wire[i+1].ori[3]=wire[i].ori[3];
			break;
		case 1:
			wire[i+1].dir=wire[i].ori[0];
			wire[i+1].ori[0]=(wire[i].dir*-1);
			wire[i+1].ori[1]=wire[i].ori[1];
			wire[i+1].ori[2]=wire[i].dir;
			wire[i+1].ori[3]=wire[i].ori[3];
			break;
		case 2:
			wire[i+1].dir=wire[i].ori[2];
			wire[i+1].ori[0]=wire[i].dir;
			wire[i+1].ori[1]=wire[i].ori[1];
			wire[i+1].ori[2]=(wire[i].dir*-1);
			wire[i+1].ori[3]=wire[i].ori[3];
			break;
		case 3:
			wire[i+1].dir=wire[i].ori[1];
			wire[i+1].ori[0]=wire[i].ori[0];
			wire[i+1].ori[1]=(wire[i].dir*-1);
			wire[i+1].ori[2]=wire[i].ori[2];
			wire[i+1].ori[3]=wire[i].dir;
			break;
		case 4:
			wire[i+1].dir=wire[i].ori[3];
			wire[i+1].ori[0]=wire[i].ori[0];
			wire[i+1].ori[1]=wire[i].dir;
			wire[i+1].ori[2]=wire[i].ori[2];
			wire[i+1].ori[3]=(wire[i].dir*-1);

	}

}*/

int main(){
	int l;
	while(1){
		scanf("%d",&l);
		if(!l)break;
		wp wire[l];
		wire[0].dir=1;
		wire[0].ori[0]=2;
		wire[0].ori[1]=3;
		wire[0].ori[2]=-2;
		wire[0].ori[3]=-3;
		char dec[3];
		int c=l-1;
		while(c){
			scanf("%s",dec);
			if(!strcmp(dec,"No"))wire[c-1].bend=0;
			if(!strcmp(dec,"+y"))wire[c-1].bend=1;
			if(!strcmp(dec,"-y"))wire[c-1].bend=2;
			if(!strcmp(dec,"+z"))wire[c-1].bend=3;
			if(!strcmp(dec,"-z"))wire[c-1].bend=4;
			--c;
		}
		int i;
		for(i=0;i<l-1;++i){
			switch(wire[i].bend){
				case 0:
					wire[i+1].dir=wire[i].dir;
					wire[i+1].ori[0]=wire[i].ori[0];
					wire[i+1].ori[1]=wire[i].ori[1];
					wire[i+1].ori[2]=wire[i].ori[2];
					wire[i+1].ori[3]=wire[i].ori[3];
					break;
				case 1:
					wire[i+1].dir=wire[i].ori[0];
					wire[i+1].ori[0]=(wire[i].dir*-1);
					wire[i+1].ori[1]=wire[i].ori[1];
					wire[i+1].ori[2]=wire[i].dir;
					wire[i+1].ori[3]=wire[i].ori[3];
					break;
				case 2:
					wire[i+1].dir=wire[i].ori[2];
					wire[i+1].ori[0]=wire[i].dir;
					wire[i+1].ori[1]=wire[i].ori[1];
					wire[i+1].ori[2]=(wire[i].dir*-1);
					wire[i+1].ori[3]=wire[i].ori[3];
					break;
				case 3:
					wire[i+1].dir=wire[i].ori[1];
					wire[i+1].ori[0]=wire[i].ori[0];
					wire[i+1].ori[1]=(wire[i].dir*-1);
					wire[i+1].ori[2]=wire[i].ori[2];
					wire[i+1].ori[3]=wire[i].dir;
					break;
				case 4:
					wire[i+1].dir=wire[i].ori[3];
					wire[i+1].ori[0]=wire[i].ori[0];
					wire[i+1].ori[1]=wire[i].dir;
					wire[i+1].ori[2]=wire[i].ori[2];
					wire[i+1].ori[3]=(wire[i].dir*-1);
			}
		}		
		switch(wire[l-1].dir){
			case 1: 
				printf("+x\n");
				break;
			case -1:
				printf("-x\n");
				break;
			case 2:
				printf("+y\n");
				break;
			case -2:
				printf("-y\n");
				break;
			case 3:
				printf("+z\n");
				break;
			case -3:
				printf("-z\n");
		}		
	}

	/*Me falta implementar como cambia la direccion
	Ideas: 
	seguir el wire desde la base hasta la punta cambiando de direccion segun los valores de bend
	*/

	return 0;
}