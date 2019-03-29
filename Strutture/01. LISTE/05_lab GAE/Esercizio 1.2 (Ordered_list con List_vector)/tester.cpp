#include "Ordered_List.h"
#include <iostream>

using namespace std;


int main()
{
  	Ordered_list<int> list1, list2;

	int x;

	/* inserting three elements into the list list1 */
	x = 1;
  	list1.insertOrd(x);
	x = 2;
  	list1.insertOrd(x);
	x = 5;
  	list1.insertOrd(x);
	x = 6;
  	list1.insertOrd(x);

	/* visualizing the list list1 */
	cout << "list1=" ; cout << list1;

	/* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */

	/*list2 = list1;
	cout << "After list2=list1, list2="; cout << list2;*/

	/* comparing for equality the lists list1 and list2 */
	/*if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;*/

	/* erasing the first element from the list list2 */
	//list2.erase(list2.begin());
	/* visualizing the list list2 */
	//cout << "After erasing the first element, list2="; cout << list2;
	/* comparing for equality the lists list1 and list2 */
	/*if (list1 == list2)
			cout << "list1 == list2" << endl;
	else
			cout << "list1 != list2" << endl;*/
			
	
	if(list1.isPalindrome()) cout<<"List1 is palindrome"<<endl;
	else cout<<"List1 is not palindrome"<<endl;
	
	/*list1.insert(3);
	cout<<"After inserting 3: ";
	cout<<list1<<endl<<endl;*/
	
	list2.insertOrd(3);
	list2.insertOrd(4);
	list2.insertOrd(7);
	cout<<"List 2 = "<<list2<<endl;
	list1.merge(list2);
	cout<<"After merge: "<<list1<<endl;
	
	
	cout<<"After seaching 3: "<<list1.search(3)<<endl<<endl;

}

