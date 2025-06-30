# Firewall Rules Optimization using IPTables

## About
This project analyzes and optimizes firewall rules for Linux IPTables, focusing on packet filtering to improve security, performance, and manageability.

---

## Introduction
Firewalls are critical network security devices that monitor and control incoming and outgoing traffic based on predefined security rules. They serve as a barrier between trusted internal networks and untrusted external networks, such as the Internet, blocking malicious traffic and unauthorized access.

In this project, we use Linux’s `iptables` to demonstrate the functioning of firewall rules, focusing on:

- **Packet Filtering:** Checks packet headers and applies rules.
- **Proxy Service & Stateful Inspection:** (Conceptual overview for context.)

We also tackle common firewall anomalies through rule optimization:

- **Shadowing**  
- **Generalization**  
- **Redundancy**

---

## Objectives
- Parse and analyze existing IPTables firewall rules.
- Detect and resolve:
  - Shadowing anomalies (hidden rules).
  - Generalization anomalies (overlapping rules).
  - Redundancy anomalies (unnecessary rules).
- Reorder and optimize rules to improve firewall performance and maintain intended security policy.

---

## Build and Run Instructions

- Clone this repository
```
git clone <repository-url>
cd <repository-directory>
```
- Build
```
mkdir build && cd build
cmake ..
make
```

- Extract existing iptables rules
```
sudo iptables-save > input_file_path.txt
```

- Run the optimization
```
./IPTABLES_RULES_OPTIMIZATION
```

---

## Outputs


![image](https://github.com/user-attachments/assets/5396e457-9df6-4210-90b3-a9485baad608) *Original IP Firewall Rules*

![image](https://github.com/user-attachments/assets/aa0cc08c-c6d8-4e0b-ab99-5fcf206d6080) *Shadowing Anomaly Removed*


![image](https://github.com/user-attachments/assets/4dfd8aef-ee1f-406f-b266-bc83fea40101) *Redundant Rules Removed*


![image](https://github.com/user-attachments/assets/212c71ac-e4f3-4ba3-b70a-f62432a95572) *Final Optimized Rules*


---

## Notes

The project was delevoped in collaboration with Shravasti Sarkar for Application Delivery Controller and Virtualization Course at RVCE
