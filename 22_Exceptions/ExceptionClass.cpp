//#include <iostream>
//#include <exception>
//using namespace std;
//
//// Exception for password invalid error
//class PasswordInvalidException : public exception
//{
//public:
//	PasswordInvalidException(const char* message) : exception(message) {}
//};
//
//// Exception for password small error
//class PasswordIsSmallException : public exception
//{
//	int length;
//public:
//	PasswordIsSmallException(const char* message, int length) : length(length), 
//		exception(message) {}
//	void Message() const
//	{
//		cout << what() << endl;
//		cout << "Actual Lenght: " << length << endl;
//	}
//};
//
//// Exception for invalid argument error
//class ArgZero
//{
//	int numOfArg;
//public:
//	ArgZero(int num) : numOfArg(num) {}
//	void message()
//	{
//		cout << "Argument: " << numOfArg
//			<< " - equals zero!\n";
//	}
//};
//
//
//void Login(const char* login, const char* password)
//{
//	if (strlen(password) < 6)
//		throw PasswordIsSmallException("Password small!", strlen(password));
//
//	if (!isalpha(password[0]) || !islower(password[0]))
//		throw PasswordInvalidException("Password invalid!");
//
//	if (!isalpha(login[0]) || !isupper(login[0]))
//		throw exception("Login invalid!");
//
//	cout << "Logining...\n";
//}
////void Login(const char* login, const char* password)
////{
////	if (strlen(password) < 6)
////		throw exception("Password small!", strlen(password));
////
////	if (!isalpha(password[0]) || !islower(password[0]))
////		throw exception("Password invalid!");
////
////	if (!isalpha(login[0]) || !isupper(login[0]))
////		throw exception("Login invalid!");
////
////	cout << "Logining...\n";
////}
//
//
//void main()
//{
//	// Login
//	char login[100];
//	char pass[100];
//
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << "Enter login: ";
//		cin >> login;
//		cout << "Enter password: ";
//		cin >> pass;
//
//		try
//		{
//			Login(login, pass);
//			break;
//		}
//		catch (PasswordInvalidException& e)
//		{
//			cout << "Invalid... do something:\n";
//			cout << e.what() << endl;
//			cout << "A-Z, a-z, 0-9\n";
//		}
//		catch (PasswordIsSmallException& e)
//		{
//			cout << "Small... do something:\n";
//			e.Message();
//			cout << "Length must be more than  6 symbols\n";
//		}
//		catch (exception& e)
//		{
//			cout << "General error...\n";
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unknown exception!\n";
//		}
//	}
//
//	system("pause");
//}