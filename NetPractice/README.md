*This project has been created as part of the 42 curriculum by `dstumpf`.*

# NetPractice

## Description

NetPractice is a hands-on introduction to computer networking. It consists of **10 levels**, each showing a small simulated network that doesn't work. The goal is to fix it by editing the configurable fields (IP addresses, subnet masks, default gateways and routing tables) until every objective of the level is met, for example *"host A must be able to talk to host B"*.

The levels get progressively harder: they start with two hosts on the same network, then add switches, routers, multiple subnets, chained routers and finally the Internet.

Concepts practised along the way:

- IPv4 addressing and the structure of an IP address
- Subnet masks and CIDR notation (`/24`, `/26`, …)
- Network, broadcast and usable host addresses
- Switches (same network) vs. routers (between networks)
- Default gateways and next hops
- Routing tables and the `default` / `0.0.0.0/0` route
- Private vs. public address ranges and reaching the Internet
- Making sure traffic can travel **both** ways

All networks in this project are simulated; no real hardware or network is involved.

## Instructions

### Running the training interface
 
1. Download the `net_practice` archive from the project page on the 42 intranet.
2. Extract it:
```sh
   tar -xzf net_practice.<version>.tgz
```
3. Execute ```./run.sh```.
4. Enter your 42 login and start the **training** mode.

### Solving a level
1. Read the goals at the top of the level.
2. Edit the fields that are not greyed out.
3. Click **Check again** and read the logs at the bottom of the page: they explain exactly why a packet was dropped.
4. Once every goal is green, click **Get my config** to export the configuration file.

### Submission
The root of the repository contains:

```
.
├── README.md
└── 10 exported configuration files (one per level)
```

### Finding the network a host belongs to
Example: `192.168.1.10/26`
 
1. **Network address** = `IP & mask`. With `/26`, only the first 2 bits of the last octet belong to the network. `10` is `00001010`, so those 2 bits are `00` making the last octet of the network address `0` → `192.168.1.0`.
2. **Broadcast address**: `/26` is `1100 0000` in the last octet. The last `1` stands for `64`, so all the bits after it set to `1` add up to `63`. Add that to the network address: `0 + 63` → `192.168.1.63`.
3. **Usable host range**: everything strictly between the two → `192.168.1.1 – 192.168.1.62`.

## Resources

### References
- [Subnetting basics](https://www.geeksforgeeks.org/computer-networks/introduction-to-subnetting/)

### AI usage
Claude (AI) was used to draft and structure this README and to help me understand the basic networking concepts behind the project (TCP/IP addressing, subnet masks, default gateways, routers and
switches, OSI layers). All ten levels were solved without AI.
