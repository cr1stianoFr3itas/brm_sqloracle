/*******************************************************************
*
* Criado em: 07/06/21 
*
* Autor: Cristiano Freitas
*
* Atualizado por ultimo em: 10/06/21
* 
* CUST OPS
*
********************************************************************/

/*
 * This file contains the opcode definitions for the PCM API.
 */

#ifndef _CUSTOM_OPS_H
#define	_CUSTOM_OPS_H

/*
 * Define the opcodes.
 *
 *
 * do NOT! change these values!
 *
 *
 * NOTE: the opcode number space is divided into space reserved for
 *       definition by Portal and space reserved for customer definition.
 *       The spaces are allocated as follows:
 *
 *              opcode number           reserved for
 *              ------------------------------------
 *              0 - 9999                Portal Only
 *              10,000 - 999,999        Customer Use
 *              1,000,000 - 9,999,999   Portal Only
 *              10,000,000+             Customer Use
 *
 * DO NOT define custom opcodes in the ranges reserved for Portal.
 *
 * DO NOT ADD ANY defines OTHER THAN OPCODES IN THIS FILE. THIS FILE IS USED
 * TO AUTOMATICALLY GENERATE OPCODE MAPPINGS.
 *
 */
	/*
	 * Generic Opcodes
	 */



#define AC_OP_CUST_SEARCH_NAME		10000	/* invalid operation */
#define AC_OP_CUST_CREATE_CLIENT  10001 /* create client */
#define AC_OP_CUST_WRITE          10002 /*cust write*/






        /* opcodes for ar tool Reserved till 1320 */

#endif /* !_CUSTOM_OPS_H */
