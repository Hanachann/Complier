/*
 * types.h - 
 *
 * All types and functions declared in this header file begin with "Ty_"
 * Linked list types end with "..list"
 */
#ifndef __TYPE_H__
#define __TYPE_H__

typedef struct Ty_ty_ *Ty_ty;
typedef struct Ty_tyList_ *Ty_tyList;
typedef struct Ty_field_ *Ty_field;
typedef struct Ty_fieldList_ *Ty_fieldList;

struct Ty_ty_ {
	enum {
		Ty_record, Ty_nil, Ty_int, Ty_string, Ty_array,
		Ty_name, Ty_void
	} kind;
	union {
		Ty_fieldList record;
		Ty_ty array;
		struct { S_symbol sym; Ty_ty ty; } name;
	} u;
};

struct Ty_tyList_ { Ty_ty t; Ty_tyList next; };
struct Ty_field_ { S_symbol name; Ty_ty ty; };
struct Ty_fieldList_ { Ty_field f; Ty_fieldList next; };

Ty_ty Ty_Nil(void);
Ty_ty Ty_Int(void);
Ty_ty Ty_String(void);
Ty_ty Ty_Void(void);

Ty_ty Ty_Record(Ty_fieldList fields);
Ty_ty Ty_Array(Ty_ty ty);
Ty_ty Ty_Name(S_symbol sym, Ty_ty ty);

Ty_tyList Ty_TyList(Ty_ty t, Ty_tyList next);
Ty_field Ty_Field(S_symbol name, Ty_ty ty);
Ty_fieldList Ty_FieldList(Ty_field f, Ty_fieldList next);

Ty_ty Ty_actualTy(Ty_ty ty);
int Ty_match(Ty_ty a, Ty_ty b);
/*
void Ty_print(Ty_ty t);
void TyList_print(Ty_tyList list);
*/

#endif
