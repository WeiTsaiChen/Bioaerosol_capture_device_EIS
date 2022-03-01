my $module_name="";
my $author="";
my $date="";

print "======================================================================\n";
print "==                           Module Creator                         ==\n";
print "==                       Version : 2009/11/24                       ==\n";
print "======================================================================\n";
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
print "Please Input C filename:";
$new_c_filename=<>;
chomp($new_c_filename);
return if ($new_c_filename!~/\S/);

my $c_src=$module_name.'\c_src';
my $asm_src=$module_name.'\asm_src';
my $drv_src=$module_name.'\drv_src';
my $copyright="Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved";
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
my $typedef_str="TYPEDEF STRUCT DEFINITION";
my $c_plus="C PLUS PLUS COMPATIABLE DEFINITION";
my $step="\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
#`mkdir $module_name`;
#`mkdir $c_src`;
#`mkdir $asm_src`;
#`mkdir $drv_src`;
#new_udef();
#new_init();
#new_idef();
new_task();
#new_glb_vars();
#new_drv();
print "Module Name: $module_name\n";
print "Author     : $author \n";
print "Create Date: $date\n";
print "Thank you ";

sub new_task()
{
	my $Mname=lc($module_name);
	my $def=uc($module_name).'_'.uc($new_c_filename)."_H";
	my $filename=lc($module_name).'_'.$new_c_filename.'.h';
	my $path_filename=$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_box($file,$c_plus);	
	print $file "#ifdef __cplusplus\n";
	print $file "extern \"C\"\n";
	print $file "{\n";
	print $file "#endif\n";
	new_file_detail($file,$filename,"Here declare task function");
	new_box($file,$include_str);
	new_box($file,$marco_definition_str);
	new_box($file,$func_str);
	print $file "void ".lc($module_name).'_'.lc($new_c_filename).'();'."\n";
	new_box($file,$c_plus);	
	print $file "#ifdef __cplusplus\n";
	print $file "}\n";
	print $file "#endif\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=lc($module_name).'_'.$new_c_filename.'.c';
	my $path_filename=$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,"Task Subroutine");
	new_box($file,$include_str);
	print $file "#include \"..\\drv_src\\".$Mname."_drv.h\" \n";
	print $file "#include \"".$Mname."_glb_vars.h\"\n";
	new_box($file,$c_plus);
	print $file "#ifdef __cplusplus\n";
	print $file "extern \"C\"\n";
	print $file "{\n";
	print $file "#endif\n";
	$func_name=$Mname.'_'.lc($new_c_filename);	
	new_func($file,$func_name,"task function");
	print $file "void $func_name()\n";
	print $file "{\n\n";
	print $file "}\n";
	print $file "#ifdef __cplusplus\n";
	print $file "}\n";
	print $file "#endif\n\n";
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
