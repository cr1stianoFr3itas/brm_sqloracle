/*******************************************************************
*
* Criado em: 07/06/21 
*
* Autor: Cristiano Freitas
*
* Atualizado por ultimo em: 10/06/21
* 
* CUST CUSTOM CONFIG 
*
********************************************************************/

#ifndef lint
static  char    Sccs_id[] = "@(#)$Id: fm_cust_custom_config.c /cgbubrm_7.5.0.portalbase/1 2015/11/27 05:40:50 nishahan Exp $";
#endif

#include <stdio.h>	/* for FILE * in pcm.h */
#include "ops/inv.h"
#include "pcm.h"
#include "cm_fm.h"
#include "custom_ops.h"


#ifdef WIN32
__declspec(dllexport) void * fm_cust_custom_config_func();
#endif


/*******************************************************************
 *******************************************************************/
struct cm_fm_config fm_cust_custom_config[] = {


	{ AC_OP_CUST_SEARCH_NAME,  "op_inv_pol_mycustomop" },
  { AC_OP_CUST_CREATE_CLIENT,  "op_cust_create_client" },
  { AC_OP_CUST_WRITE, "op_new_op_code"},   
   
  { 0,(char*)0}

};

#ifdef WIN32
void *
fm_cust_custom_config_func()
{
	return ((void *) (fm_cust_custom_config));
}
#endif
