.data
	avg dd 0
	;v1 dd rcx
	;v2 dd rdx
	;v3 dd r8
	;v4 dd r9
	;v5 dd [rsp + 8]
	;v6 dd [rsp + 9]
	;v7 dd [rsp + 10]
	;v8 dd [rsp + 11]
	;v9 dd [rsp + 12]

	;w1 dd [rsp + 13]
	;w2 dd [rsp + 14]
	;w3 dd [rsp + 15]
	;w4 dd [rsp + 16]
	;w5 dd [rsp + 17]
	;w6 dd [rsp + 18]
	;w7 dd [rsp + 19]
	;w8 dd [rsp + 20]
	;w9 dd [rsp + 21]
.code
wavg_calc_asm proc
	;zapis parametrów v1, v2, v3, v4 do rejestru xmm0
	movss xmm0, rcx
	;movss xmm0, rdx
	;movss xmm0, r8
	;movss xmm0, r9
	;zapis parametrów w1, w2, w3, w4 do rejestru xmm1
	;movss xmm1, [rsp + 8]
	;movss xmm1, [rsp + 8]
	;movss xmm1, [rsp + 8]
	;movss xmm1, [rsp + 8]
	;mov rax, 12
	ret
wavg_calc_asm endp
end
