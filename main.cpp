
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "basic_parser.h"
#include "enums.h"
#include "helper_functions.h"
#include "shadowing_anomaly_detection.h"
#include "generalized_anomaly_detection.h"
using namespace std;

#include <string>

bool starts_with(const string &str, const string &prefix)
{
  return str.find(prefix) == 0;
}

int main(int argv, char* argc[])
{
  // Open the file
  if(argv < 2){
    cout << " Usage : ./IPTABLES_RULES_OPTIMIZER input_file_path.txt" << endl;
    exit(0);
  }
  ifstream input_file(argc[1]);
  vector<FW_RULE> rules;
  FW_RULE rule;

  // Check if the file is open
  if (!input_file.is_open())
  {
    cerr << "Error opening file" << endl;
    return 1;
  }

  // Read each line of the file
  string line;
  while (getline(input_file, line))
  {
    reset_rule(rule);
    // Process the line
    if (starts_with(line, "-A"))
    {
      cout << "Parsing line : " << line << endl;
      rule = parseIptablesRule(line);
      //print_rule(rule);
    }
    else
      rule.unoptimized_rule = line;
    rules.push_back(rule);
  }
  // string rule = "iptables -A INPUT -s 192.168.1.2 -p tcp --dport 80 -j ACCEPT";
  //  Close the file
  rules = resolve_shadowing_anomaly(rules);
  rules = resolve_generalized_anomalies(rules);
  rules = resolve_redundancy_anomalies(rules);
  write_rules(rules, "/home/shravasti/Documents/RVCE/adc/firewall_rules_output.txt");
  input_file.close();
  return 0;
}