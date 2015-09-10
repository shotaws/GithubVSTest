#include "itpp/itcomm.h"
#include "itpp/itstat.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#define P(var) cout<<#var" = "<<var<<endl
#define DN 1 //from 1 is more effective
#define UN 14751
#define N 10
#define M 5

using namespace std;
using namespace itpp;

int main(int argc, char* argv[]){
	RNG_randomize();

	int i, j;
	string str[] = {"test", ".txt"};
	string str2[] = {"stat_test", ".txt"};
	
	/*ofstream ofs( "test.txt", ios::out);*/
	ofstream *of = new ofstream[2];
	//stringstream ss;
	of[0].open(str[0]+str[1],ios::out);
	of[1].open(str2[0]+str2[1],ios::out);

	for (j=0; j<N; j++){

		string tmp;

		//config
		switch(j){
			case 0:
				tmp = "] cbr-destination = *";
				break;
			case 1:
				tmp = "] cbr-payload-size-bytes = 100";
				break;
			case 2:
				tmp = "] cbr-traffic-defined-by = Interval";
				break;
			case 3:
				tmp = "] cbr-interval = 0.100000000";
				break;
			case 4:
				tmp = "] cbr-start-time = 10.000000000";
				break;
			case 5:
				tmp = "] cbr-end-time = 50.000000000";
				break;
			case 6:
				tmp = "] cbr-priority = 0";
				break;
			case 7:
				tmp = "] cbr-start-time-max-jitter = 1.0000000000";
				break;
			case 8:
				tmp = "] cbr-use-virtual-payload = false";
				break;
			case 9:
				tmp = "] cbr-auto-port-mode = true";
				break;
		}

		for (i=DN; i<=UN; i++)
			of[0] << "[" << i << ";cbr" << i << tmp << endl;
			//of[j] << "[" << i << ";cbr" << i << tmp << endl;

	}

	
	for (j=0; j<M; j++){
		string tmp;

		//config
		switch(j){
			case 0:
				tmp = "_PacketSent 2s 0s inf_time";
				break;
			case 1:
				tmp = "_PacketReceived 2s 0s inf_time";
				break;
			case 2:
				tmp = "_BytesSent 2s 0s inf_time";
				break;
			case 3:
				tmp = "_BytesReceived 2s 0s inf_time";
				break;
			case 4:
				tmp = "_EndToEndDelay 2s 0s inf_time";
				break;
		}

		for (i=DN; i<=UN; i++)
			of[1] << "* CbrApp_cbr" << i << tmp << endl;
			//of[j] << "[" << i << ";cbr" << i << tmp << endl;

	}



	//for (i=DN;i<=UN;i++){
	//	//cout << "[" << i << ";cbr" << i << "] cbr-destination = *" << endl;
	//	ofs << "[" << i << ";cbr" << i << "] cbr-destination = *" << endl;
	//}
	//
	//for (i=DN;i<=UN;i++)
	//	ofs << "[" << i << ";cbr" << i << "] cbr-payload-size-bytes = 100" << endl;

	delete[] of;

	return 0;
}
