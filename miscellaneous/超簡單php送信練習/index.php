<?php
  $email = $_POST['email'];

  $sub = "這作業好難";
  $msg = "這作業超難";
  $rec = "$email";
  
  if(mail($rec,$sub,$msg)):
   echo "信件已經發送成功。";//寄信成功就會顯示的提示訊息
  else:
   echo "信件發送失敗！";//寄信失敗顯示的錯誤訊息
  endif;
?>
