//#include <iostream>
//#include <exception>
//using namespace std;
//
//float Divide(float a, float b)
//{
//    float res = 0;
//    //exception ex("Divide by zero");
//    if (b == 0)
//    {
//        //throw catch try
//        cout << "Can't divide by zero!!!" << endl;
//        //throw ex;
//        throw exception("Divide by zero");
//    }
//    if (b == 1)
//    {
//        //return 404;
//        throw 404;
//    }
//    if (b == 5)
//    {
//        throw "Divide by 5";
//    }
//    if (b == 6)
//        throw 'Q';
//    else
//    {
//        res = a / b;
//        cout << "Result : " << res << endl;
//        return res;
//    }    
//      cout << "Result : " << res << endl;
//}
//
//
//int main()
//{
//
//    float a, b;
//    cout << "Enter numbers : ";
//    cin >> a >> b;
//    try
//    {
//        float res = Divide(a, b);
//        cout << "Result in main : " << res << endl;
//    }  
//      catch (exception  ex)
//    {
//        cout<< ex.what()<<endl;
//    }   
//    catch (int ex)
//    {
//        cout << "Page not found... Error : ";
//        cout << ex << endl;
//    }
//    catch (const char* ex)
//    {
//        cout << ex << endl;
//    }
//    catch (...)
//    {
//        cout << "Unknown error" << endl;
//    }
//    cout << "Continue.............." << endl;
//    cout << "Continue.............." << endl;
//    cout << "Continue.............." << endl;
//    cout << "Continue.............." << endl;
//   
//    
//}
//
