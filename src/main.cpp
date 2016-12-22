#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>

int main(int argc, char* argv[])
{

	boost::property_tree::ptree ptree_root, employee_items, item1, item2, item3;
	item1.put<std::string>("firstName","John");
	item1.put<std::string>("lastName","Doe");
	item1.put<int>("age",20);
	item1.put<bool>("marry",true);
	employee_items.push_back(make_pair("", item1));
	item2.put<std::string>("firstName","Anna");
	item2.put<std::string>("lastName","Smith");
	item2.put<int>("age",25);
	employee_items.push_back(make_pair("", item2));
	item3.put<std::string>("firstName","Peter");
	item3.put<std::string>("lastName","Jones");
	item3.put<int>("age",30);
	employee_items.push_back(make_pair("", item3));

	ptree_root.put_child("employees", employee_items);
	ptree_root.add("master.firstName", "wang");
	ptree_root.add("master.lastName", "yun");
	ptree_root.add("master.age", 24);
	ptree_root.put("master.lastName", "dan");
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptree_root.get_child("employees"))
	{
		std::cout << v.second.get<std::string>("firstName") << " "<< v.second.get<std::string>("lastName") << "\n";
	}
	boost::property_tree::write_json("employees.json", ptree_root);
	return 0;
}
