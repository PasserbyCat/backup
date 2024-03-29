transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/digital/full {D:/digital/full/full.v}

vlog -vlog01compat -work work +incdir+D:/digital/full {D:/digital/full/full_test.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L cycloneiii_ver -L rtl_work -L work -voptargs="+acc" full_test

add wave *
view structure
view signals
run -all
