<?php
  $email = $_POST['email'];
  $foodname = $_POST['foodname'];
  $foodmake = $_POST['foodmake'];
  $foodneed = $_POST['foodneed'];

  $sub = "您的食譜";
  $msg = "    $foodname
  
      《食材》
$foodneed
  
      《步驟》
$foodmake";
  $rec = "$email";
  
  if(mail($rec,$sub,$msg)):
   echo "信件已經發送成功。";//寄信成功就會顯示的提示訊息
  else:
   echo "信件發送失敗！";//寄信失敗顯示的錯誤訊息
  endif;
?>
