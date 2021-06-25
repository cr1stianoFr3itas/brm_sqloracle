
/*
   Dev. Cristiano Freitas
   email: junior.brown.eda@gmail.com
   Data de inicio do projeto: 20/05/2021
   Data de "Final" do projeto: 13/06/2021
   CUST FIELDS

*/



/*
 * This file contains definitions of the field elements in the PIN API.
 */

#ifndef _CUSTOM_FLDS_H
#define	_CUSTOM_FLDS_H

/*
 * Definition of common/PIN-pre-defined field number values.
 * Field numbers are used to represent fields in objects,
 * but also used as a general parameter mechanism for special commands.
 *
 * Multiple object types will use the same field number if the meaning
 * of the field is the same in both object types.
 *
 * do NOT CHANGE the values - NEVER replace, ALWAYS ADD to end of a
 * functional block.
 *
 * NOTE: the field number space is divided into space reserved for
 *	 definition by Portal and space reserved for customer definition.
 *	 The spaces are allocated as follows:
 *
 *		field number		reserved for
 *		------------------------------------
 *		0 - 9999		Portal Only
 *		10,000 - 999,999	Customer Use
 *		1,000,000 - 9,999,999	Portal Only
 *		10,000,000+		Customer Use
 *
 * DO NOT define custom fields in the ranges reserved for Portal.
 *
 */




		/* special fields (0 - 15) */
#define PIN_FLD_RESERVED		0	/* not used */
#define PIN_FLD_ERR_BUF			PIN_MAKE_FLD(PIN_FLDT_ERR, 1)
		
   
   /*DEFINE*/
   
#define AC_FLD_BIRTHDAY   PIN_MAKE_FLD(PIN_FLDT_TSTAMP, 10037)
#define AC__FLD_GENDER   PIN_MAKE_FLD(PIN_FLDT_STR, 10036)
#define AC__FLD__ADDRESS   PIN_MAKE_FLD(PIN_FLDT_ARRAY, 10028)
#define AC_FLD_COMPLEMENT   PIN_MAKE_FLD(PIN_FLDT_STR, 10032)
#define AC__FLD__CEP   PIN_MAKE_FLD(PIN_FLDT_DEC, 10029)
#define AC__FLD__NUMBER   PIN_MAKE_FLD(PIN_FLDT_INT, 10031)
#define AC__FLD__CHILDRENS   PIN_MAKE_FLD(PIN_FLDT_ARRAY, 10038)
#define AC__FLD__NAME_CHILDREN   PIN_MAKE_FLD(PIN_FLDT_STR, 10039)
#define AC__FLD__CPF   PIN_MAKE_FLD(PIN_FLDT_STR, 10033)
#define AC__FLD__NAME   PIN_MAKE_FLD(PIN_FLDT_STR, 10027)
#define AC___FLD__AGE   PIN_MAKE_FLD(PIN_FLDT_INT, 10035)


    
    
    
    
    








        /* reserved  9999 for other general fields */
#endif
# /* !_CUSTOM_FLDS_H */
