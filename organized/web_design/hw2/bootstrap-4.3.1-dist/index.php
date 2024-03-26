<?php

require_once('../TCPDF/tcpdf_import.php');

$name = $_POST['name'];
$phone = $_POST['phone'];
$email = $_POST['email'];
$birthday = $_POST['birthday'];
$major = $_POST['major'];
$nodisease = $_POST['nodisease'];
$heartdisease = $_POST['heartdisease'];
$asthma = $_POST['asthma'];
$hypertension = $_POST['hypertension'];
$otherdisease = $_POST['otherdisease'];
$rating = $_POST['rating'];

/*---------------- Sent Mail Start -----------------*/

mb_internal_encoding("utf-8");

$to="$email";
$subject=mb_encode_mimeheader("感謝您的報名","utf-8");
$message="
        <p>名字</p>
        <p>$name</p>
        <p>手機號碼</p>
		<p>$phone</p>
		<p>系別</p>
		<p>$major</p>
		<p>生日</p>
		<p>$birthday</p>
		<p>電子郵件</p>
        <p>$email</p> 
		<p>至今罹患過哪些重大疾病</p>
		<p>$nodisease$heartdisease$asthma$hypertension$otherdisease</p>
		<p>對本活動的期待</p>
		<p>$rating</p>
";
$headers="MIME-Version: 1.0\r\n";
$headers.="Content-type: text/html; charset=utf-8\r\n";
$headers.="From:".mb_encode_mimeheader("四資迎新報名","utf-8")."<s1081447@mail.yzu.edu.tw>\r\n";

mail($to, $subject, $message, $headers);

/*---------------- Sent Mail End -------------------*/

/*---------------- Print PDF Start -----------------*/

$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
$pdf->setPrintHeader(false);
$pdf->setPrintFooter(false);
$pdf->SetFont('cid0jp','', 18); 
$pdf->AddPage();

$html = <<<EOF

<table border="1" >

    <tr>
        <td>名字</td>
        <td>$name</td>
        <td>手機號碼</td>
		<td colspan="2">$phone</td>
    </tr>
	
	<tr>
		<td>系別</td>
		<td>$major</td>
		<td>生日</td>
		<td colspan="3">$birthday</td>
	</tr>
	
    <tr>
		<td>電子郵件</td>
        <td colspan="4">$email</td>
    </tr>
	
	<tr>
		<td colspan="2">至今罹患過哪些重大疾病</td>
		<td colspan="3">$nodisease$heartdisease$asthma$hypertension$otherdisease</td>
	</tr>
	
	<tr>
		<td colspan="2">對本活動的期待</td>
		<td colspan="3" color="#00ff00">$rating</td>
	</tr>
	
</table>

EOF;

/*---------------- Print PDF End -------------------*/

$pdf->writeHTML($html);
$pdf->lastPage();
$pdf->Output('order.pdf', 'I');
?>