#include "db.h"
#include <mysql++.h>
#include <iostream>
#include "Common.h"
using namespace std;

int main()
{
    Db db;
    mysqlpp::Connection conn(false);
    if(conn.connect(db.getdb(), db.getserver(), db.getuser(), db.getpassword())){
        cout << "connect db succeed!" << '\n';
    }
    else{
        cout << "connect db failed!" << '\n';
    }

    cout << "Please enter the number you want to operate:" << '\n';
    cout << "1.Find all group chat records" << '\n';
    cout << "2.Find someone's chat history in a group chat" << '\n';
    cout << "3.Delete someone's chat history in a group chat" << '\n';
    cout << "4.Delete all chat records in the group chat" <<'\n';
    cout << "5.Find the chat history of someone and someone" << '\n';
    cout << "6.Delete someone's chat history with someone" << '\n';
    cout << "0.break!" << '\n';

    int n = 0;
    while(cin >> n)
    {
        if(n == 1 || n == 2){
            mysqlpp::Query query = conn.query();
            if(n == 1) query = conn.query("SELECT * FROM conver");
            else{
                int m;
                cout << "Please enter the number of the person you want to inquire about the chat history:";
                cin >> m;
               // mysqlpp::Query query = conn.query();
                query << "select * from conver where id = ""'" + to_string(m) + "'"";";
		//query.execute();
            }
            if (mysqlpp::StoreQueryResult res = query.store())
            {
                cout.setf(ios::left); //left    输出调整为左对齐.
                cout << setw(11) << "Sid" <<
                setw(50) << "text" <<         //setw(10)设置输出的域宽，不足补齐
                setw(10) << "time" << endl;

                mysqlpp::StoreQueryResult::const_iterator it;
                for (it = res.begin(); it != res.end(); ++it)
                {
                    mysqlpp::Row row = *it;
                    cout << setw(10) << row[0] << ' ' <<
                    setw(49) << row[1] << ' ' <<
                    setw(9) << row[2] << ' ' <<
                    endl;
                }
            }
        }
        else if(n == 3){
            int m;
            cout << "Please enter the number of the person you want to delete about the chat history:";
            cin >> m;
            mysqlpp::Query query = conn.query();
            query << "delete from conver where id = ""'" + to_string(m) + "'"";";
            query.execute();
            cout << "Delete succeed!" <<'\n';
        }
        else if(n == 4){
            int m;
            cout << "Are you sure you want to delete the data of the whole table?" << '\n';
            cout << "If you are sure, enter 1, otherwise enter 2:";
            cin >> m;
            if(n == 1){
                mysqlpp::Query query = conn.query();
                query << "truncate table conver;";
                query.execute();
                cout << "Delete succeed!" <<'\n';
            }
            else if(n == 2) continue;
        }
        else if(n == 5){
            mysqlpp::Query query = conn.query();
            cout <<"Please enter the numbers of both parties to the chat:";
            int x, y;
            cin >> x >> y;

            query << "select * from ppconver where send_id = ""'" + to_string(x) + "'"" and recv_id = ""'" + to_string(y) + "'"" union select * from ppconver where send_id = ""'" + to_string(y) + "'"" and recv_id = ""'" + to_string(x) + "'"";";
		  //  query.execute();

            if (mysqlpp::StoreQueryResult res = query.store())
            {
                cout.setf(ios::left); //left    输出调整为左对齐.
                cout << setw(11) << "send_id" <<
                setw(11) << "recv_id" <<
                setw(50) << "text" <<         //setw(10)设置输出的域宽，不足补齐
                setw(10) << "time" << endl;
    
                mysqlpp::StoreQueryResult::const_iterator it;
                for (it = res.begin(); it != res.end(); ++it)
                {
                    mysqlpp::Row row = *it;
                    cout << setw(10) << row[0] << ' ' <<
                    setw(10) << row[1] << ' ' <<
                    setw(49) << row[2] << ' ' <<
                    setw(9) << row[3] << ' ' <<
                    endl;
                }
            }
        }
        else if(n == 6){
            mysqlpp::Query query = conn.query();
            cout << "Please enter the two-party numbers to delete the chat record:";
            int x, y;
            cin >> x >> y;
             
            query << "Delete from ppconver where send_id = ""'" + to_string(x) + "'"" and recv_id = ""'" + to_string(y) + "'"" union delete from ppconver where send_id = ""'" + to_string(y) + "'"" and recv_id = ""'" + to_string(x) + "'"";";
            query.execute();
	    cout << "delete succeed!" << '\n';
        }
	else if(n == 0) break;
    }
    return 0;
}
