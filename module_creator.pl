my $module_name="";
my $author="";
my $date="";
my $STEP="/";
my $dir_step="\\";
print "Please Input Module Name:";
$module_name=<>;
chomp($module_name);
return if ($module_name!~/\S/);
print "Please Input Author Name:";
$author=<>;
chomp($author);
return if ($author!~/\S/);
print "Please Input Create Date:";
$date=<>;
chomp($date);
return if ($date!~/\S/);

my $c_src=$module_name.$dir_step.'c_src';
my $asm_src=$module_name.$dir_step.'asm_src';
my $drv_src=$module_name.$dir_step.'drv_src';
my $copyright="Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved";
my $const_str="EXTERNAL GLOBAL CONSTANCE / VARIABLES IN EEPROM";
my $condition_str="CONDICTION COMPILE";
my $include_str="INCLUDE FILES / EXTERNAL VARIABLES";
my $api_for_str="API FOR OTHER MODULES";
my $api_str="API CALL FROM OTHER MODULES";
my $func_str="FUNCTION PROTOTYPES";
my $external_def="EXTERNAL VARIABLE ALLOC";
my $glb_vars="DECLARE GLOBE VARIABLE";
my $io_definition_str="I/O PORT DEFINITION";
my $marco_definition_str="MACRO DEFINITION";
my $step="\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
`mkdir $module_name`;
`mkdir $c_src`;
`mkdir $asm_src`;
`mkdir $drv_src`;
new_udef();
new_init();
new_idef();
new_task();
new_glb_vars();
new_drv();
print "It's done!\n";
print "Module Name: $module_name\n";
print "Author     : $author \n";
print "Create Date: $date\n";
$module_name=<>;

sub new_drv()
{
	my $Mname=lc($module_name);
	my $def=uc($module_name)."_DRV_H";
	my $filename=lc($module_name).'_drv.h';
	my $path_filename=lc($module_name).$STEP.'drv_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here declare driver function");
	new_box($file,$include_str);
	new_box($file,$io_definition_str);
	new_box($file,$marco_definition_str);
	new_box($file,$func_str);
	print $file "void ".lc($module_name).'_sfr_init();'."\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=$Mname.'_drv.c';
	my $path_filename=$Mname.$STEP.'drv_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,"Driver Subroutine");
	new_box($file,$include_str);
	print $file "#include \"".$Mname."_drv.h\" \n";
	$func_name=$Mname.'_sfr_init';	
	new_func($file,$func_name,"Register initial function");
	print $file "void $func_name()\n";
	print $file "{\n\n";
	print $file "}\n";
	close($file);	
}

sub new_glb_vars()
{
	my $Mname=lc($module_name);
	my $def=uc($module_name)."_GLB_VARS_H";
	my $filename=lc($module_name).'_glb_vars.h';
	my $path_filename=lc($module_name).$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here declare globe variable");
	new_box($file,$include_str);
	new_box($file,$external_def);
	print $file "#ifdef ".uc($module_name)."_ALLOC\n";
	print $file "\t#define EXTERNAL\n";
	print $file "#else\n";
	print $file "\t#define EXTERNAL extern\n";
	print $file "#endif\n";
	new_box($file,$glb_vars);
	new_box($file,$func_str);
	print $file "void ".lc($module_name).'_glb_vars_init();'."\n";
	print $file "#undef EXTERNAL\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=$Mname.'_glb_vars.c';
	my $path_filename=$Mname.$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,"Init globe variable");
	new_box($file,$include_str);

	$func_name=$Mname.'_glb_vars_init';
	print $file "#define ".uc($module_name)."_ALLOC\n";
	print $file "#include \"".lc($module_name)."_glb_vars.h\"\n";
	print $file "#undef ".uc($module_name)."_ALLOC\n";	
	new_func($file,$func_name,"task function");
	print $file "void $func_name()\n";
	print $file "{\n\n";
	print $file "}\n";
	close($file);	
}


sub new_task()
{
	my $Mname=lc($module_name);
	my $def=uc($module_name)."_TASK_H";
	my $filename=lc($module_name).'_task.h';
	my $path_filename=lc($module_name).$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here declare task function");
	new_box($file,$include_str);
	new_box($file,$marco_definition_str);
	new_box($file,$func_str);
	print $file "void ".lc($module_name).'_task();'."\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=$Mname.'_task.c';
	my $path_filename=$Mname.$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,"Task Subroutine");
	new_box($file,$include_str);
	print $file "#include \"..".$STEP."drv_src".$STEP.$Mname."_drv.h\" \n";
	print $file "#include \"".$Mname."_glb_vars.h\"\n";
	$func_name=$Mname.'_task';	
	new_func($file,$func_name,"task function");
	print $file "void $func_name()\n";
	print $file "{\n\n";
	print $file "}\n";
	close($file);	
}

sub new_idef()
{
	my $def=uc($module_name)."_IDEF_H";
	my $filename=lc($module_name).'_idef.h';
	my $path_filename=lc($module_name).$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here define internal constant");
	new_box($file,$const_str);
	print $file "#endif		// $def \n";
	close($file);
}

sub new_init()
{
	my $Mname=lc($module_name);
	my $def=uc($module_name)."_INIT_H";
	my $filename=lc($module_name).'_init.h';
	my $path_filename=lc($module_name).$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here declare initial function");
	new_box($file,$include_str);
	new_box($file,$func_str);
	print $file "void ".lc($module_name).'_init();'."\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=$Mname.'_init.c';
	my $path_filename=$Mname.$STEP.'c_src'.$STEP.$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,"Initial Subroutine");
	new_box($file,$include_str);
	print $file "#include \"..".$STEP."drv_src".$STEP.$Mname."_drv.h\" \n";
	print $file "#include \"".$Mname."_glb_vars.h\"\n";
	$func_name=$Mname.'_init';	
	new_func($file,$func_name,"initial function");
	print $file "void $func_name()\n";
	print $file "{\n";
	print $file "\t".$Mname."_sfr_init();\n";
	print $file "\t".$Mname."_glb_vars_init();\n";
	print $file "}\n";
	close($file);	
}

sub new_udef()
{
	my $def=uc($module_name)."_UDEF_H";
	my $filename=lc($module_name).'_udef.h';
	my $path_filename=lc($module_name).$STEP.$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here define all API");
	new_box($file,$const_str);
	new_box($file,$condition_str);
	new_box($file,$include_str);
	print $file "#include \"c_src".$STEP.lc($module_name).'_init.h'."\"\n";
	new_box($file,$api_for_str);
	print $file "#define\t".uc($module_name).'_INIT_API()'.$step.lc($module_name).'_init()'."\n";
	new_box($file,$api_str);
	new_box($file,$func_str);
	print $file "#endif		// $def \n";
	close($file);
}

sub new_func()
{
	my $file=shift;
	my $func=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@fn \t\t\t $func\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//! \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//! \@param \t\t None\n";
	print $file "//\n";
	print $file "//! \@return \t None\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_info()
{
	my $file=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//! \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_file_detail()
{
	my $file=shift;
	my $filename=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@file \t\t $filename\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//  \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_box()
{
	my $file=shift;
	my $str=shift;
	my @char=split(//,$str);
	print $file "//**********************************************************************************************************************\n";
 	print $file "//\n";
 	print $file "// ";
	for (my $i=0;$i<@char;$i++)
	{
		print $file "$char[$i] ";
	}
	print $file "\n";
 	print $file "//\n";
 	print $file "//**********************************************************************************************************************\n";
	#print $file "\n";
}



