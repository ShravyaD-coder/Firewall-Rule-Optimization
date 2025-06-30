#include "redundancy_anomaly.h"
#include "helper_functions.h"
#include "nps_functions.h"

bool is_subset(const FW_RULE &a, const FW_RULE &b)
{
	if(a.unoptimized_rule != "" || b.unoptimized_rule != "")
	return false;

    if (a.action != "" && a.action != b.action)
            return false;

    if (a.protocol != "" && a.protocol != b.protocol)
            return false;

    if (a.src_address != "" && !ip_is_contained(a.src_address, b.src_address))
            return false;

    if (a.src_port != "" && a.src_port != b.src_port)
            return false;
    
    if (a.dst_address != "" && !ip_is_contained(a.dst_address, b.dst_address))
            return false;

    if (a.dst_port != "" && a.dst_port != b.dst_port)
            return false;		
	print_rule(b);
	cout << " is a subset of ";
	print_rule(a);
	cout << endl<<endl;
    return true;
}

// Driver Code
vector<FW_RULE> resolve_redendancy_anomalies(vector<FW_RULE> rules)
{
	vector<FW_RULE> result;
	int n=rules.size();
	vector<int>redundant;
	for(int i=0;i<n;i++)
	{
		redundant[i]=0;
	}

	for (int i = 0; i < rules.size(); i++)
	{
		for (int j = i+1; j < rules.size(); j++)
		{
			if(is_subset(rules[i], rules[j]) == true){
				redundant[j]=1;
			}
			else if(is_subset(rules[j], rules[i]) == true){
				// rule[i] is a subset of rule[j]
				redundant[i]=1;
			}
		}
	}

	for (int i = 0; i<rules.size(); i++)
	{
		if(redundant[i]!=1)
		{
			result.push_back(rules[i]);
		}
	}
	cout << "The rules are \n";
	for (auto rule_number : rule_number_ordering)
		cout << rule_number <<endl;
	cout << endl;

	return result;
}