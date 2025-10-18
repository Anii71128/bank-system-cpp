#include<iostream>
#include<vector>
using namespace std;

class BankAccount{
	private:
		string name;
		int accountNum;
		double balance;
	public:
		BankAccount(string n, int ac,double bal){
			name = n;
			accountNum = ac;
			balance = bal;
		}
		string getName(){
			return name;
		}
		int getAccountNum(){
			return accountNum;
			}
		double getBalance(){
			return balance;
		}
		void deposit(double amount){
			balance = balance + amount;
		}
		void withdraw(double amount){
			if(balance >= amount){
				balance = balance - amount;
				cout<<"\t\tPenarikan berhasil..."<<endl;
			}else{
				cout<<"\t\tSaldo tidak mencukupi...."<<endl;
			}
		}
};
class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void AddAccount(string name,int accountNum,double balance){
			accounts.push_back(BankAccount(name,accountNum,balance));
		}
		void showAllAccounts(){
			cout<<"\t\tSemua Pemegang akun "<<endl;
			for(int i = 0; i<accounts.size();i++){
				cout<<"\t\tName :"<<accounts[i].getName()<<" Account Number :"<<accounts[i].getAccountNum()<<" Balance :"<<accounts[i].getBalance()<<endl;
			}
		}
		void searchAccount(int account){
			cout<<"\t\tPemegang Akun "<<endl;
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==account){
				cout<<"\t\tName :"<<accounts[i].getName()<<" Account Number :"<<accounts[i].getAccountNum()<<" Balance :"<<accounts[i].getBalance()<<endl;
				}
			}
		}
		BankAccount* findAccount(int accountNum){
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNum()==accountNum){
					return &accounts[i];
				}
			}
		}
};
main(){

	BankManagement bank;
	int choice;
	char op;
	do{
		system("cls");
		cout<<"\t\t======== Banking Management System ========\n"<<endl;
		cout<<"\t\t\tMenu Utama"<<endl;
		cout<<"\t\t1. Buat akun Baru"<<endl;
		cout<<"\t\t2. Tampilkan Semua Akun"<<endl;
		cout<<"\t\t3. Akun pencarian"<<endl;
		cout<<"\t\t4. Menyetror Uang"<<endl;
		cout<<"\t\t5. MEnarik Uang"<<endl;
		cout<<"\t\t6. Keluar"<<endl;
		cout<<"\t\t-------------------------------"<<endl;
		cout<<"\t\tMasukan Pilihan Anda :";
		cin>>choice;
		switch(choice){
			case 1:{
				string name;
				int accountNum;
				double balance;
				cout<<"\t\tMasukkan Nama :";
				cin>>name;
				cout<<"\t\tMasukkan Nomor Rekening :";
				cin>>accountNum;
				cout<<"\t\tMasukkan Saldo Awal :";
				cin>>balance;
				bank.AddAccount(name,accountNum,balance);
				cout<<"\t\tAkun Berhasil Dibuat...."<<endl;
				break;
			}
			case 2:{
				bank.showAllAccounts();
				break;
			}
			case 3:{
				int accountNum;
				cout<<"\t\tMasukkan Nomor Rekening :";
				cin>>accountNum;
				bank.searchAccount(accountNum);
				break;
			}
			case 4:{
				int accountNum;
				double amount;
				cout<<"\t\tMasukkan Nomor Rekening Untuk Menyetor Uang :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tMasukkan Jumlah Yang Akan Disetor :";
					cin>>amount;
					account->deposit(amount);
					cout<<"\t\t"<<amount<<" Setoran Berhasil ...."<<endl;
				}else{
					cout<<"\t\tAkun Tidak Ditemukkan ..."<<endl;
				}
				break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout<<"\t\tMasukkan Nomor Rekening Untuk Menarik Uang :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tMasukkan Jumlah Yang Akan Ditarik :";
					cin>>amount;
					account->withdraw(amount);

				}else{
					cout<<"\t\tAkun Tidak Ditemukan ..."<<endl;
				}
				break;
			}
			case 6:{
				exit(1);
				break;
			}
	}
	cout<<"\t\tApakah Anda Ingin Melanjutkan Atau Keluar [Y/N]: ";
	cin>>op;

	}while(op == 'y'||op =='Y');

}
