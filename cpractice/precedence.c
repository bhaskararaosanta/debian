C predence and associativity table notes:
1. Top to bottom means operators precedence will reduce
2. associaivity may be left to right or vice versa which 
   are in same group.

Rememberance: 1. F_A_S_POST 2. LNEG_1sCOM_UP_UM_PRE_PTR_SIZE_CAST 
	      3. MUL_DIV_MOD 4. BP_BM 5. BLS_BRS 6. L_LEQ_G_GEQ 
	      7. EQ_NEQ 8. BAND 9. BXOR 10. BOR 11. LAND 
	      12. LOR 13. TER 14. ASSIGN 15. COMMA

-----------------------------------------------------------------
operator meaning of operator			Associativity
-----------------------------------------------------------------
()	Function Call or expression
[]	Array subscript				
->	pointer to struct member		1. Left to Right
.	struct member selection
++	Post fix - increment				 
--	Post fix - Decrement
-----------------------------------------------------------------
!	Logical negation
~	Bitwise 1's compliment
+	Unary plus
-	Unary minus
++	Pre fix - increment			2. Right to Left
--	Pre fix - Decrement
&	Derefence operator
*	pointer reference
sizeof	size of an object
(type)	Typecast converter
-----------------------------------------------------------------
*	Multiplication
/	Divide					3. Left to Right
%	Modulo operator
-----------------------------------------------------------------
+	Binary plus
-	Binary minus				4. Left to Right
-----------------------------------------------------------------
<<	Bit wise Left shift
>>	Bit wise Right shift			5. Left to Right
-----------------------------------------------------------------
<	Less than
<=	Less than or equal to
>	Greater than				6. Left to Right
>=	Greater than or equal to
-----------------------------------------------------------------
==	Equal to
!=	Not equal to				7. Left to Right
-----------------------------------------------------------------
&	Bit-wise AND				8. Left to Right
-----------------------------------------------------------------
^	Bit-wise XOR				9. Left to Right
-----------------------------------------------------------------
|	Bit-wise OR				10. Left to Right
-----------------------------------------------------------------
&&	Logical AND				11. Left to Right
-----------------------------------------------------------------
||	Logical OR				12. Left to Right
-----------------------------------------------------------------
?:	Ternary operator			13. Right to Left
-----------------------------------------------------------------
=
*=
/=
%=
+=	Assignment operators		 	14. Right to Left
-=
&=
^=
|=
<<=
>>=
-----------------------------------------------------------------
,	Comma					15. Left to Right
-----------------------------------------------------------------
