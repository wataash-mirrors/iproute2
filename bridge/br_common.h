/* SPDX-License-Identifier: GPL-2.0 */

#define MDB_RTA(r) \
		((struct rtattr *)(((char *)(r)) + RTA_ALIGN(sizeof(struct br_mdb_entry))))

#define MDB_RTR_RTA(r) \
		((struct rtattr *)(((char *)(r)) + RTA_ALIGN(sizeof(__u32))))

int print_linkinfo(struct nlmsghdr *n, void *arg);
int print_mdb_mon(struct nlmsghdr *n, void *arg);
int print_fdb(struct nlmsghdr *n, void *arg);
void print_stp_state(__u8 state);
int parse_stp_state(const char *arg);
int print_vlan_rtm(struct nlmsghdr *n, void *arg, bool monitor,
		   bool global_only);
int print_vnifilter_rtm(struct nlmsghdr *n, void *arg);
void br_print_router_port_stats(struct rtattr *pattr);
void print_headers(FILE *fp, const char *label);

int do_fdb(int argc, char **argv);
int do_mdb(int argc, char **argv);
int do_monitor(int argc, char **argv);
int do_mst(int argc, char **argv);
int do_vlan(int argc, char **argv);
int do_link(int argc, char **argv);
int do_vni(int argc, char **argv);

extern int preferred_family;
extern int show_stats;
extern int show_details;
extern int timestamp;
extern int compress_vlans;
extern int json;
extern struct rtnl_handle rth;
