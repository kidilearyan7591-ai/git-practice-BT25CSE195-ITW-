#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int userID;
    string userName;
    int friendCount;

public:
    void getData()
    {
        cout << "Enter User ID: ";
        cin >> userID;

        cin.ignore();
        cout << "Enter User Name: ";
        getline(cin, userName);

        cout << "Enter Friend Count: ";
        cin >> friendCount;
    }

    void addFriend()
    {
        friendCount++;
    }

    void removeFriend()
    {
        if (friendCount > 0)
        {
            friendCount--;
        }
        else
        {
            cout << "Friend count cannot be negative." << endl;
        }
    }

    User operator+(User u)
    {
        User result;

        result.userID = userID;
        result.userName = userName + " & " + u.userName;
        result.friendCount = friendCount + u.friendCount;

        return result;
    }

    bool operator>(User u)
    {
        return friendCount > u.friendCount;
    }

    void display()
    {
        cout << "User ID: " << userID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Friend Count: " << friendCount << endl;
    }
};

int main()
{
    User user1, user2, mergedUser;

    cout << "Enter details of User 1" << endl;
    user1.getData();

    cout << "\nEnter details of User 2" << endl;
    user2.getData();

    user1.addFriend();

    cout << "\nAfter adding a friend to User 1:" << endl;
    user1.display();

    user2.removeFriend();

    cout << "\nAfter removing a friend from User 2:" << endl;
    user2.display();

    if (user1 > user2)
    {
        cout << "\nUser 1 has more friends." << endl;
    }
    else if (user2 > user1)
    {
        cout << "\nUser 2 has more friends." << endl;
    }
    else
    {
        cout << "\nBoth users have the same number of friends." << endl;
    }

    mergedUser = user1 + user2;

    cout << "\nMerged Friend Network:" << endl;
    mergedUser.display();

    cout << "\nFinal User 1 Details:" << endl;
    user1.display();

    cout << "\nFinal User 2 Details:" << endl;
    user2.display();

    return 0;
}