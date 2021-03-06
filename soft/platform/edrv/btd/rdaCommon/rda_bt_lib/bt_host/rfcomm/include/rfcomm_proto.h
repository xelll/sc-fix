/***********************************************************************
 *
 * MODULE NAME:    rfcomm_proto.h
 * PROJECT CODE:   Bluestream host stack
 * DESCRIPTION:    RFCOMM Function Prototypes
 * MAINTAINER:     David Airlie
 * CREATION DATE:  1 May 2000
 *
 * SOURCE CONTROL: $Id: rfcomm_proto.h 1532 2010-08-23 05:47:34Z huazeng $
 *
 * LICENSE:
 *     This source code is copyright (c) 2000-2002 Parthus Technologies Inc.
 *     All rights reserved.
 *
 ***********************************************************************/
#ifndef _PRH_RFCOMM_PROTO_H_
#define _PRH_RFCOMM_PROTO_H_
/* This file is automatically generated with "make proto". DO NOT EDIT */


/*The following definitions come from  port_ent_api.c  */
#if PRH_RFCOMM_PE_SUPPORT==1
t_api prh_pe_layer_ctrl(u_int8 flags);
APIDECL1 t_api APIDECL2 PE_SrvRegisterPort(char *port, prh_t_rfcomm_schan *serv_chan, void (*port_callback)(prh_t_rfcomm_schan schan, t_bdaddr bd_addr, u_int8 connection_state));
APIDECL1 t_api APIDECL2 PE_SrvDeregisterPort(prh_t_rfcomm_schan schan);
APIDECL1 t_api APIDECL2 PE_SrvDisconnectPort(prh_t_rfcomm_schan schan);
APIDECL1 t_api APIDECL2 PE_CliConnectPort(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan rem_schan, char *pName, void (*port_callback)(prh_t_rfcomm_schan schan, t_bdaddr bd_addr, u_int8 connection_state));
APIDECL1 t_api APIDECL2 PE_CliDisconnectPort(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan serverchannel);
#endif

/*The following definitions come from  rfcomm_core.c  */

int prh_rfcomm_init(u_int32 flags);
int prh_rfcomm_core_init(u_int32 flags);
int prh_rfcomm_reset(void);
int prh_rfcomm_check_channel_state(prh_t_rfcomm_schan schan);
void prh_rfcomm_l2cap_connect_ind(u_int8 eventType, t_L2_ControlCallbackArgs *args);
int prh_rfcomm_add_l2cap_inst(struct prh_rfcomm_l2cap_inst *instance);
int prh_rfcomm_l2cap_cid_cmp(void *cmpin, void *compwith);
int prh_rfcomm_lookup_l2cap_inst_by_cid(prh_t_rfcomm_cid cid, struct prh_rfcomm_l2cap_inst **l2cap_inst_ptr);
int prh_rfcomm_l2cap_bdaddr_cmp(void *cmpin, void *compwith);
int prh_rfcomm_lookup_l2cap_inst_by_bd_addr(t_bdaddr bd_addr, struct prh_rfcomm_l2cap_inst **l2cap_inst_ptr);
int prh_rfcomm_remove_l2cap_inst(struct prh_rfcomm_l2cap_inst *l2cap_inst, int do_callback);
int prh_rfcomm_l2cap_remove_all_inst_helper(void *data, void *func_info);
int prh_rfcomm_remove_all_l2cap_inst(void);
int prh_rfcomm_schan_cmp(void *cmpin, void *compwith);
int prh_rfcomm_lookup_server_inst_by_schan(prh_t_rfcomm_schan schan, struct prh_rfcomm_server_inst **server_inst_ptr);
int prh_rfcomm_remove_server_inst_by_schan(prh_t_rfcomm_schan schan, struct prh_rfcomm_server_inst **server_inst_ptr);
/*int prh_rfcomm_remove_server_inst(struct prh_rfcomm_server_inst *server_inst);*/
int prh_rfcomm_remove_all_servers(void);
int prh_rfcomm_validate_and_lock_l2cap_inst_by_ptr(struct prh_rfcomm_l2cap_inst *l2cap_inst);

t_api prh_rfcomm_cc_data_ind(prh_t_rfcomm_dlci dlci0, struct host_buf *buffer, void *multi_inst);
t_api prh_rfcomm_cc_cancel_timer(struct prh_rfcomm_dlc_inst *dlc0_inst);
t_api prh_rfcomm_cc_process_msc(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
t_api prh_rfcomm_cc_process_pn(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
t_api prh_rfcomm_cc_process_test(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
int prh_rfcomm_tfunc_flow_dlci(void *data, void *func_info);
t_api prh_rfcomm_cc_process_fcon(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
t_api prh_rfcomm_cc_process_fcoff(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
t_api prh_rfcomm_cc_process_rls(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
t_api prh_rfcomm_cc_process_rpn(struct prh_rfcomm_l2cap_inst *self, struct host_buf *frame);
void prh_rfcomm_cc_timeout_cb(void *param);
t_api prh_rfcomm_cc_transmit_cmesg(struct prh_rfcomm_l2cap_inst *self, struct host_buf *buffer, u_int8 cresp);

/*The following definitions come from  rfcomm_ctrl_frames.c  */

int prh_rfcomm_cc_create_test(struct host_buf *frame, u_int8 cresp);
int prh_rfcomm_cc_destroy_test(struct host_buf *frame);
int prh_rfcomm_cc_create_fcon(struct host_buf *frame, u_int8 cresp);
int prh_rfcomm_cc_create_fcoff(struct host_buf *frame, u_int8 cresp);
int prh_rfcomm_cc_create_nsc(struct host_buf *frame, u_int8 cresp, u_int8 nscom, u_int8 nscomm_cr);
int prh_rfcomm_cc_create_rpn_req(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci);
int prh_rfcomm_cc_create_rpn_comm(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci ,prh_t_rfcomm_port_params *port_parameters);
int prh_rfcomm_cc_create_msc(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_control_params *ctrl_params);
int prh_rfcomm_cc_create_rls(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_line_stat_params line_stat_params);
int prh_rfcomm_cc_create_pn(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params);
int prh_rfcomm_cc_create_credit_pn(struct host_buf *frame, u_int8 cresp, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, u_int8 clbits, u_int8 kbits);

/*The following definitions come from  rfcomm_dlc_state.c  */

t_api prh_rfcomm_dlc_init(struct prh_rfcomm_l2cap_inst *l2cap_inst, prh_t_rfcomm_dlci dlci, struct prh_rfcomm_dlc_inst **instance, u_int8 locked);
int prh_rfcomm_dlc_do_event(struct prh_rfcomm_dlc_inst *instance, PRH_RFCOMM_EVENT event, struct prh_rfcomm_event_info *info);
void prh_rfcomm_dlc_next_state(struct prh_rfcomm_dlc_inst *self, PRH_RFCOMM_DLC_STATE state);
void prh_rfcomm_ack_timeout_cb(void *param);

/*The following definitions come from  rfcomm_entity_core.c  */

t_api prh_rfcomm_entity_init(u_int32 flags);
t_api prh_rfcomm_entity_shutdown(u_int32 flags);
int prh_rfcomm_entity_rfstart_ind_cb(t_bdaddr bd_addr, prh_t_rfcomm_start_sys_params *system_parameters, prh_t_rfcomm_accept accept, void *multi_inst);
t_api prh_rfcomm_entity_rfstart_conf_cb(t_bdaddr bd_addr, prh_t_rfcomm_start_sys_params *system_parameters, prh_t_rfcomm_accept accept, void *multi_inst);
int prh_rfcomm_open_multiplexer(t_bdaddr remote_bd_addr, void **multi_inst);
int prh_rfcomm_entity_connect_port(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan rem_schan, prh_t_rfcomm_dlci *dlci, prh_t_rfcomm_dlc_params *dlc_params, struct prh_rfcomm_dlc_cb *cbs, void **multi_inst_ptr);
int prh_rfcomm_entity_remove_all_pending_conns(void);

/*The following definitions come from  rfcomm_frames.c  */

int prh_rfcomm_create_sabm(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int8 pbit, u_int32 cresp);
int prh_rfcomm_create_ua(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int8 fbit, u_int32 cresp);
int prh_rfcomm_create_dm(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int8 fbit, u_int32 cresp);
int prh_rfcomm_create_disc(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int8 fbit, u_int32 cresp);
int prh_rfcomm_create_uih(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int32 cresp, u_int8 pfbit);  //zhu jianguo changed it. 2008.12.5
int prh_rfcomm_create_uih_credit(struct host_buf *frame, prh_t_rfcomm_dlci DLCI, u_int32 cresp, u_int8 num_credits);
int prh_rfcomm_destroy_uih(struct host_buf *frame);
int prh_rfcomm_add_fcs(struct host_buf *frame, int fcs_len);
int prh_rfcomm_rx_fcs(struct host_buf *frame, int fcs_len);
int prh_rfcomm_dump_frame(struct host_buf *frame, int tx);

/*The following definitions come from  rfcomm_l2cap.c  */

int prh_rfcomm_l2cap_init(struct prh_rfcomm_l2cap_inst **l2cap_inst_ptr, t_bdaddr bd_addr);
void prh_rfcomm_l2cap_data_ind_cb(u_int16 cid, struct host_buf *p_buf);
void prh_rfcomm_l2cap_config_ind_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
void prh_rfcomm_l2cap_config_cfm_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
void prh_rfcomm_l2cap_flow_ind_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
void prh_rfcomm_l2cap_disc_ind_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
void prh_rfcomm_l2cap_disc_cfm_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
void prh_rfcomm_l2cap_connect_cfm_cb(u_int8 eventType, t_L2_ControlCallbackArgs *args);
int prh_rfcomm_reg_dlc_instance(struct prh_rfcomm_l2cap_inst *self, prh_t_rfcomm_dlci dlci, struct prh_rfcomm_dlc_inst *instance);
int prh_rfcomm_dlc_dlci_cmp_helper(void *cmpin, void *compwith);
int prh_rfcomm_lookup_dlci_instance(struct prh_rfcomm_l2cap_inst *self, prh_t_rfcomm_dlci dlci, struct prh_rfcomm_dlc_inst **instance);
int prh_rfcomm_remove_dlc_instance(struct prh_rfcomm_l2cap_inst *self, prh_t_rfcomm_dlci dlci, struct prh_rfcomm_dlc_inst **ret_inst);
int prh_rfcomm_dlc_remove_all_helper(void *data, void *func_info);
int prh_rfcomm_remove_all_dlc_instance(struct prh_rfcomm_l2cap_inst *self, int do_release);
int prh_rfcomm_lookup_dlci_instance_and_lock(struct prh_rfcomm_l2cap_inst *self, prh_t_rfcomm_dlci dlci, struct prh_rfcomm_dlc_inst **instance);
int prh_rfcomm_free_dlc_instance(struct prh_rfcomm_dlc_inst *self);
/*The following definitions come from  rfcomm_l2cap_state.c  */

t_api prh_rfcomm_l2cap_do_event(struct prh_rfcomm_l2cap_inst *l2cap_inst, PRH_RFCOMM_EVENT event, struct prh_rfcomm_event_info *info);
void prh_rfcomm_l2cap_next_state(struct prh_rfcomm_l2cap_inst *l2cap_inst, PRH_RFCOMM_L2CAP_STATE state);
int prh_rfcomm_l2cap_process_data(struct prh_rfcomm_l2cap_inst *l2cap_inst, struct prh_rfcomm_event_info *info);
int prh_rfcomm_l2cap_dispatch_data(struct prh_rfcomm_dlc_inst *instance, struct prh_rfcomm_event_info *info);

/*The following definitions come from  rfcomm_pe.c  */

void prh_rfcomm_init_pe_struct(struct prh_rfcomm_pe_port *pe_info);
void prh_rfcomm_free_pe_struct(struct prh_rfcomm_pe_port *pe_info);
int prh_rfcomm_pe_connect_port(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan rem_schan, const char *pName, prh_t_rfcomm_dlci *dlci, struct prh_rfcomm_pe_port **pe_info_ptr, u_int16 max_frame_size,  void (*port_callback)(prh_t_rfcomm_schan schan, t_bdaddr bd_addr, u_int8 connection_state));
t_api prh_rfcomm_pe_disconnect_remote_serverchannel(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan serverchannel, struct prh_rfcomm_pe_port **pe_info_ptr);
int prh_rfcomm_pe_disconnect_local_server_channel(struct prh_rfcomm_pe_port **pe_info_ptr, prh_t_rfcomm_schan schan);
t_api port_ent_dlc_estab_ind_cb(t_bdaddr bd_addr, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, void *multi_inst);
t_api port_ent_dlc_estab_conf_cb(t_bdaddr bd_addr, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, prh_t_rfcomm_accept accept, void *multi_inst);
t_api prh_rfcomm_pe_alloc_schan(prh_t_rfcomm_schan *p_schan);
int prh_rfcomm_pe_add_port_entity(struct prh_rfcomm_pe_port *self);
int prh_rfcomm_pe_portnum_cmp(void *cmpin, void *compwith);
int prh_rfcomm_pe_remove_port_entity_by_portnum(struct prh_rfcomm_pe_port **port, u_int32 portnum);
int prh_rfcomm_pe_lookup_port_entity_by_portnum(struct prh_rfcomm_pe_port **port, u_int32 portnum);
int prh_rfcomm_pe_addrdlci_cmp(void *cmpin, void *compwith);
int prh_rfcomm_pe_lookup_port_entity_by_addr_and_dlci(struct prh_rfcomm_pe_port **port, t_bdaddr bdaddr, u_int8 dlci);
int prh_rfcomm_pe_remove_port_entity_by_addr_and_dlci(struct prh_rfcomm_pe_port **port, t_bdaddr bdaddr, u_int8 dlci);


int prh_rfcomm_entity_connect_port(t_bdaddr remote_bd_addr, prh_t_rfcomm_schan rem_schan, prh_t_rfcomm_dlci *dlci, prh_t_rfcomm_dlc_params *dlc_params, struct prh_rfcomm_dlc_cb *cbs, void **multi_inst_ptr);

/*The following definitions come from  rfcomm_ue_api.c  */

t_api PRH_RFCOMM_UE_Register_Server(prh_t_rfcomm_schan schan, struct prh_rfcomm_dlc_cb *dlc_cbs);
t_api PRH_RFCOMM_UE_Deregister_Server(prh_t_rfcomm_schan schan);
t_api PRH_RFCOMM_UE_Set_Channel_Open(prh_t_rfcomm_schan schan);
t_api PRH_RFCOMM_UE_Set_Channel_Closed(prh_t_rfcomm_schan schan);
t_api PRH_RFCOMM_UE_Get_Channel_State(prh_t_rfcomm_schan schan);
t_api PRH_RFCOMM_UE_Start_Req(t_bdaddr bd_addr, prh_t_rfcomm_start_sys_params *system_parameters, struct prh_rfcomm_multi_cb *callbacks, void **multi_inst);
t_api PRH_RFCOMM_UE_Start_Resp(t_bdaddr bd_addr, prh_t_rfcomm_start_sys_params *system_parameters, prh_t_rfcomm_accept accept,  struct prh_rfcomm_multi_cb *callbacks, void *multi_inst);
t_api PRH_RFCOMM_UE_register_rfstart_ind_cb(int (*PRH_RFCOMM_UE_Start_Ind_cb)(t_bdaddr, prh_t_rfcomm_start_sys_params *, prh_t_rfcomm_accept, void *));
t_api PRH_RFCOMM_UE_DLC_Estab_Req(t_bdaddr bd_addr, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, struct prh_rfcomm_dlc_cb *callbacks, void *multi_inst);
t_api PRH_RFCOMM_UE_DLC_Estab_Resp(t_bdaddr bd_addr, prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, prh_t_rfcomm_accept accept, void *multi_inst);
t_api PRH_RFCOMM_UE_DLC_Rel_Req(prh_t_rfcomm_dlci dlci, void *multi_inst);
t_api PRH_RFCOMM_UE_Close_Req(void *multi_inst);
t_api PRH_RFCOMM_UE_Test_Req(struct host_buf *frame, void *multi_inst);
t_api PRH_RFCOMM_UE_Flow_Req(prh_t_rfcomm_flow_state state, void *multi_inst);
t_api PRH_RFCOMM_UE_Data_Req(prh_t_rfcomm_dlci dlci, struct host_buf *buffer, void *multi_inst);
t_api PRH_RFCOMM_UE_Portneg_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_port_params *port_parameters, void *multi_inst);
t_api PRH_RFCOMM_UE_Portneg_Resp(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_port_params *port_parameters, prh_t_rfcomm_accept accept, void *multi_inst);
t_api PRH_RFCOMM_UE_Control_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_control_params *control_params, void *multi_inst);
t_api PRH_RFCOMM_UE_Linestatus_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_line_stat_params line_stat_params, void *multi_inst);
t_api PRH_RFCOMM_UE_Parneg_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, void *multi_inst);
t_api PRH_RFCOMM_UE_Parneg_Resp(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, prh_t_rfcomm_accept accept, void *multi_inst);
t_api PRH_RFCOMM_UE_Get_Multiplexer_State(t_bdaddr bd_addr, void **multi_inst);
t_api PRH_RFCOMM_UE_Parneg_Credit_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, u_int8 init_credits, void *multi_inst);
t_api PRH_RFCOMM_UE_Parneg_Credit_Resp(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, prh_t_rfcomm_accept accept, u_int8 init_credits, void *multi_inst);
t_api PRH_RFCOMM_UE_Set_Credit_Mode(prh_t_rfcomm_dlci dlci, u_int8 auto_credit_issue, void *multi_inst);
t_api PRH_RFCOMM_UE_Issue_Credits(prh_t_rfcomm_dlci dlci, u_int8 num_credits, void *multi_inst);

t_api __prh_rfcomm_ue_Parneg_Credit_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, u_int8 init_credits, void *multi_inst, u_int8 locking);
t_api __prh_rfcomm_ue_Parneg_Req(prh_t_rfcomm_dlci dlci, prh_t_rfcomm_dlc_params *dlc_params, void *multi_inst, u_int8 locking);
t_api PRH_RFCOMM_UE_Get_Write_Buffer(t_bdaddr bd_addr, prh_t_rfcomm_dlci dlci, u_int16 frame_size, u_int32 flags, struct host_buf **frame);
t_api PRH_RFCOMM_UE_Release_Write_Buffer(struct host_buf *frame);

t_api prh_rfcomm_credit_peer_nocredit(struct prh_rfcomm_dlc_inst *self);

t_api prh_rfcomm_dlci0_lock_and_transmit_cmesg(struct prh_rfcomm_l2cap_inst *self, struct host_buf *buffer, u_int8 cresp);

#endif /* _PROTO_H_ */
