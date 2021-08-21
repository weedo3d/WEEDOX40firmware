/**
* Copyright (C) 2021 Wiibooxtech Perron
*/

/**
* Multi-language character definition
* The corresponding language of the elements in the array is as follows:
*
* 0 - CN / Chinese
* 1 - EN / English
* 2 - KANA / Japanese
* 3 - ES / Spanish
* 4 - FR / French
* 5 - DE / German
* 6 - IT / Italy
* 7 - NL / Dutch
*/

#ifndef LANGUAGE_MULTI_H
#define LANGUAGE_MULTI_H

const char MSG_WIFINOTCONNECTED	[] PROGMEM = {"connecting..."};
const char MSG_UNKNOWN [] PROGMEM = {"UNKNOWN"};
const char MSG_NONE [] PROGMEM = {"NONE"};

const char MMSG_EMPTY[] PROGMEM = { " " };
const char MMSG_UNKNOWN_TIME[] PROGMEM = { "??h??m" };

const char MMSG_SPEED_VALUE1[8] PROGMEM = { "  25%" };
const char MMSG_SPEED_VALUE2[8] PROGMEM = { "  50%" };
const char MMSG_SPEED_VALUE3[8] PROGMEM = { "  100%" };
const char MMSG_SPEED_VALUE4[8] PROGMEM = { "  200%" };
const char MMSG_SPEED_VALUE5[8] PROGMEM = { "  400%" };
const char MMSG_SPEED_VALUE6[8] PROGMEM = { "  600%" };
const char TEMP_STRING[] PROGMEM = { "%d℃" };

const char MMSG_ERR_HOMING_FAILED[8][53] PROGMEM = {
	"回原点失败",			// 回原点失败
	"Homing failed",
	"ホーミング失敗",
	"Homing fallo",
    "Echec origine",
	"Anfahren der Startposition (Home) fehlgeschlagen",
	"Home fallito",
    "Homing fout"
};

const char MMSG_ERR_PROBING_FAILED[8][55] PROGMEM = {
	"自动调平失败",			// 自动调平失败
	"Probing failed",
	"プロービング失敗",
	"Fallo de sondeo",
    "Echec sonde",
	"Messung des Düsen-/Druckbettabstands fehlgeschlagen",
	"Probing fallito",
    "Sensor fout"
};

const char MMSG_SMARTCONFIG_TITLE[8][20] PROGMEM = {
	"设置WIFI网络",			
	"WIFI CONFIG",
	"無線LAN設定",
	"CONFIGURACION WIFI",
    "CONFIG WIFI",
    "WIFI Konfiguration",
    "CONFIG. WIFI",
    "WiFi configuratie"
};

const char MMSG_SMARTCONFIG_TEXT[8][660] PROGMEM = {
	"主界面右上角显示网络连接状态,联网后会显示IP地址.\r\nOFF: 未连接到WIFI网络\r\n使用手机或电脑连接到WIFI热点ESP32WIFIWDxxxxxx\r\n使用浏览器访问http://10.10.0.1:88/, 页面会显示附近可用的WIFI网络. 点击网络名后输入密码，点击Join. 页面提示Success表示联网成功, 然后重启打印机.\r\n始终显示connecting...: WIFI设备故障",
	"The upper right icon on the main menu shows the wifi\r\nstatus, a IP address will be displayed after networking.\r\nOFF: Not connected to WIFI network. Use phone or computer to join the hotspot ESP32WIFIWDxxxxxx\r\nUse a browser to visit http://10.10.0.1:88/\r\nClick the scanned network name and enter the password.\r\nClick Join and wait. When the page prompts Success, restart the printer.\r\nAlways showing connecting...: WIFI device failure.",
	"メインメニューの右上のアイコンはwifiステータスを示し, IPアドレスはネットワーキング後に表示されます. \r\nOFF: WIFIネットワークに接続されていません.  WIFIホットスポットESP32WIFIWDxxxxxxに接続.ブラウザを使用してhttp://10.10.0.1:88/にアクセスします.スキャンしたネットワーク名をクリックして, パスワードを入力します. [Join]をクリックして待機します. [参加して待機]をクリックします.  ページに「Success」と表示されたら、プリンタを再起動します.\r\n常に接続を表示しています...：WIFIデバイスの障害. ",
	"El icono superior derecha del menú principal muestra el estado de Wi-Fi..\r\nOFF: no conectado a la red WIFI. únete al punto de acceso ESP32WIFIWDxxxxxx. Visite http://10.10.0.1:88/. Haga clic en el nombre de la red escaneada e ingrese la contrasena. Haz clic en Join y espera. Cuando la página indique Success, reinicie la impresora.\r\nSiempre mostrando la connecting...: falla del dispositivo WIFI.",
    "L'icone en haut à droite du menu principal montre l'état du wifi, une adresse IP sera affichée après la mise en réseau.\r\nOFF: Non connecté au réseau WIFI. Utilisez le téléphone ou l'ordinateur pour rejoindre le hotspot ESP32WIFIWDxxxxxx. Utilisez un navigateur pour visiter http://10.10.0.1:88/. Cliquez sur le nom du réseau numérisé et entrez le mot de passe. Cliquez sur Joindre et attendre. Lorsque la page invite le succès, redémarrez l'imprimante.",
    "Das Icon oben rechts im Hauptmenü zeigt den Wifi-Status. Bei bestehender Netzwerkverbindung wird die IP-Addresse angezeigt.\r\nOFF: NIcht mit dem WiFi Netzwerk verbunden. Nutzen Sie eine Telefon oder den PC um sich mit dem Hotspot WIFICAMWDxxxxxx zu verbinden\r\n- Rufen Sie in einem Internetbrowser die Adresse http://10.10.0.1:88/ auf\r\n- klicken Sie den angezeigten Netzwerknamen an und geben Sie das Passwort ein.\r\n-klicken Sie auf verbinden und warten Sie. Wenn die Seite Ihnen eine erfolgreiche Verbindung anzeigt, dann starten Sie den Drucker neu.\r\nWird fortwahrend nur Verbinde... angezeigt liegt ein Problem mit der Wifi-Verbindung vor.",
    "L'icona in alto a destra sulle principali visualizzato il menu di stato del Wi-Fi, un indirizzo IP verrà visualizzato dopo rete.\r\nOFF: non connesso alla rete WIFI. Usa il telefono o il computer per unirti all'hotspot ESP32WIFIWDxxxxxx. Utilizza un browser per visitare http://10.10.0.1:88/. Fare clic sul nome della rete scansionata e immettere la password. Fai clic su Partecipa e attendi. Quando la pagina viene richiesto Successo, riavviare la stampante.",
    "Het icoon rechtsboven in het hoofdmenu geeft de WiFi status aan,\r\n\een IP-adres wordt weergegeven indien verbonden met een netwerk.\r\nIT: Niet verbonden met het WiFi netwerk. Gebruik een telefoon of computer om verbinding te maken met hotspot WIFICAMWDxxxxxx\r\nGebruik een internetbrowser om naar http://10.10.0.1:88/ te gaan.\r\nKlik op netwerk naam en voer het paswoord in.\r\nKlik op Verbind en wacht. Zodra er een verbinding tot stand is gebracht, herstart de printer.\r\nIndien de status blijft staan op Verbinden...: WiFi fout"
};

const char MMSG_OTA_TITLE[8][15] PROGMEM = {
	"WIFI固件升级",			
	"WIFI OTA",
	"WIFI OTA",
	"WIFI OTA",
    "WIFI OTA",
    "WIFI OTA",
    "WIFI OTA",
    "WiFi"
};

const char MMSG_BACK[8][11] PROGMEM = {
	"  返回",			// 
	"  Back ",
	"  戻る",
	" Volver ",
    " Arrière",
    "Hauptmenü",
    " Indietro",
    " Terug"
};

const char MMSG_WAITING[8][16] PROGMEM = {
	" 等待...",			// 
	" Waiting...",
	"待っています...",
	"Esperando...",
    "Attendre...",
    " warte...",
    "Inatteso...",
    "Even geduld..."
};

const char MMSG_OTA_LINE[8][150] PROGMEM = {
	"\r\n 正在检测更新, 请不要关闭电源\r\n 更新成功后, 请重启打印机",
	" Checking for updates,\r\n please do not turn off the power.\r\n Reboot the printer after the update.",
	" アップデートを確認して,\r\n 電源を切らないでください.\r\n 更新後にプリンタを再起動してください.",
	" Comprobando actualizaciones,\r\n Por favor, no apague la alimentación.\r\n Reinicie la impresora después de la actualización.",
    "Vérification des mises à jour,\r\nVeuillez ne pas couper l'alimentation.\r\nRedémarrez l'imprimante après la mise à jour.",
    "Suche nach Aktualisierungen...,\r\n Bitte den Drucker nicht ausschalten!\r\n Starten Sie den Drucker nach dem Update neu.",
    "Verifica aggiornamenti,\r\nsi prega di non spegnere l'alimentazione.\r\nRiavvia la stampante dopo l'aggiornamento.",
    "Zoekt naar updates,\r\nzet de printer NIET uit!\r\nHerstart de printer na het uitvoeren van de update."
};

const char MMSG_ERROR_TITLE[8][8] PROGMEM = {
	"错误",			
	"Error",
	"エラー",
	"Error",
    "Erreur",
    "Fehler",
    "Errore",
    "Fout"
};

const char MMSG_NOTICE_TITLE[8][11] PROGMEM = {
	"提示",			
	"Notice",
	"通知",
	"Notar",
    "Remarquer",
    "Anmerkung",
    "Avviso",
    "Let op"
};

const char MMSG_SDCARD_STOP[8][26] PROGMEM = {
	" 正在停止打印...",
	" Stop printing...",
	" 印刷を停止します...",
	" Dejar de imprimir ...",
    " Arrêter l'impression...",
    " beende den Druck...",
    " Interrompi la stampa...",
    " Stop printen..."
};

const char MMSG_SDCARD_PAUSE[8][30] PROGMEM = {
	" 正在暂停打印...",
	" Pause printing...",
	" 印刷を一時停止しています...",
	" Pausa la impresión ...",
    " Suspendre l'impression...",
    " pausiere den Druck...",
    " Metti in pausa la stampa...",
    " Pauseer printen..."
};

const char MMSG_SDCARD_RESUME[8][52] PROGMEM = {
	" 正在恢复打印...",
	" Resume printing...",
	" 印刷を再開しています...",
	" Reanudar la impresión ...",
    " Reprendre l'impression...",
    " führe den letzten gespeicherten Druck fort...",
    " Riprendi la stampa...",
    " Hervat printen..."
};

const char MMSG_SDCARD_SAVE[8][44] PROGMEM = {
	" 正在保存关机...",
	" Save printing...",
	" 印刷を保存しています...",
	" Guardar impresión ...",
    " Reprendre l'impression...",
    " speichere den aktuellen Druckstatus...",
    " Riprendi la stampa...",
    " Sla printen op..."
};

const char MMSG_RUNOUT_1[8][45] PROGMEM = {
	"检测到料丝缺失，打印暂停",
	"Filament runout, print paused",
	"フィラメント振れ、印刷一時停止",
	"Salida de filamento, impresión en pausa",
    "Enregistrer l'impression...",
    "Kein Filament vorhanden, Druck pausiert",
    "Salva stampa...",
    "Printfilament is op, print gepauseerd"
};

const char MMSG_CONTINUE[8][12] PROGMEM = {
	" 继续 ",			
	"Continue",
	"持続する",
	"Continuar",
    "Continuer",
    "Fortfahren",
    "Continua",
    "Hervat"
};

const char MMSG_MAIN_BUTTON1[8][12] PROGMEM = {
	"   打印",		// 打印
	"   Print",
	"  印刷する",
	" Impresión",
    " Impression",
    "  Drucken",
    "  Stampa",
    "  Print"
};

const char MMSG_MAIN_BUTTON2[8][17] PROGMEM = {
	"   维护",
	"Maintenance",
	" メンテナンス",
	"Mantenimiento",
    " Entretien",
    " Wartung",
    "Manutenzione",
    " Onderhoud"
};

const char MMSG_MAIN_BUTTON3[8][16] PROGMEM = {
	"   设置",
	"  Setting",
	"   設定",
	"  Ajuste",
    "  Réglage",
    "Einstellungen",
    " Ambiente",
    " Instelling"
};

const char MMSG_MAIN_BUTTON4[8][14] PROGMEM = {
	"   帮助",
	"   Help",
	"  助けて",
	"  Ayuda",
    " Aidez-moi",
    "   Hilfe",
    "   Aiuto",
    "   Help"
};

const char MMSG_TF_TITLE[8][32] PROGMEM = {
	"选择打印文件",
	"Select Print File",
	"印刷ファイルを選択",
	"Seleccione Imprimir Archivo",
    "Sélectionnez Fichier Imprimer",
    "Druckdatei auswahlen",
    "Seleziona Stampa file",
    "Selecteer Print Bestand"
};

const char MMSG_NEXT_PAGE[8][14] PROGMEM = {
	"  下一页   ",
	"  Next     ",
	"   次      ",
	" Siguiente ",
    " Prochain",
	" weiter",
	" Prossimo",
    " Volgende"
};

const char MMSG_PRE_PAGE[8][14] PROGMEM = {
	"  上一页   ",
	" Previous  ",
	"   前      ",
	" Anterior  ",
    " Precedent",
	"  zurück ",
	"Precedente",
    "  Vorige"
};

const char MMSG_LANGUAGE_TITLE[8][27] PROGMEM = {
	"选择界面语言",
	"Language Setting",
	"言語設定",
	"Configuración de idioma",
    "Paramètres de langue",
    "Spracheinstellungen",
    "Impostazione della lingua",
    "Taal Instelling"
};

const char MMSG_LANGUAGE_ITEM1[8][12] PROGMEM = {
	" 中文",
	" Chinese",
	" 中国語",
	" Chino",
    " Chinoise",
	" Chinesisch",
	" Cinese",
    " Chinees"
};

const char MMSG_LANGUAGE_ITEM2[8][10] PROGMEM = {
	" 英语",
	" English",
	" 英語",
	" Inglés",
    " Anglaise",
	" Englisch",
	" Inglese",
    " Engels"
};

const char MMSG_LANGUAGE_ITEM3[8][12] PROGMEM = {
	" 日语",
	" Japanese",
	" 日本語",
	" Japoneses",
    " Japonais",
	" Japanisch",
	" Giapponese",
    " Japans"
};

const char MMSG_LANGUAGE_ITEM4[8][12] PROGMEM = {
	" 西班牙语",
	" Spanish",
	" スペイン語",
	" Espanola",
    " Espanol",
	" Spanisch",
	" Spagnola",
    " Spaans"
};

const char MMSG_LANGUAGE_ITEM5[8][14] PROGMEM = {
    " 法语",
	" French",		
    " フランス語",
    " Frances",
	" Francaise",
	" Franzosisch",
	" Francese",
    " Frans"
};

const char MMSG_LANGUAGE_ITEM6[8][12] PROGMEM = {
    " 德语",
	" German",		
    " ドイツ人",
    " Aleman",			
	" Allemande",
	" Deutsche",
	" Tedesca",
    " Duitse"
};

const char MMSG_LANGUAGE_ITEM7[8][14] PROGMEM = {
    " 意大利语",
	" Italian",	
    " イタリア語",
    " Italiano",
	" Italienne",
	" Italienisch",
	" Italiana",
    " Italiaans"
};

const char MMSG_LANGUAGE_ITEM8[8][16] PROGMEM = {
    " 荷兰语",
	" Dutch",	
    " オランダの",
    " Holandesa",
	" Néerlandaise",
	"Niederlandisch",
	" olandese",
    " Nederlands"
};


const char MMSG_PREPARE_TITLE[8][32] PROGMEM = {
	"打印机维护",
	"Printer Maintenance",
	"プリンタのメンテナンス",
	"Mantenimiento de la impresora",
    "Maintenance de l'imprimante",
    "Druckerwartung",
    "Manutenzione della stampante",
    "Printer Onderhoud"
};

const char MMSG_SETTING_FILAMENT[8][26] PROGMEM = {
	"    料丝操作",
	"Filament Operation",
	"  フィラメント操作",
	"    Filamento",
    "opération filament",
    "Filamenteinstellungen",
    "    Filamento",
    "Filament bediening"
};

const char MMSG_SETTING_TEMP[8][16] PROGMEM = {
	"    温度设置",
	"   Temperature",
	"    温度設定",
	"   Temperatura",
    "   Température",
    "   Temperatur",
    "   Temperatura",
    "   Temperatuur"
};

const char MMSG_SETTING_SPEED[8][20] PROGMEM = {
	"    速度设置",
	"     Speed",
	"  スピード設定",
	"   Velocidad",
    "    Vitesse",
	"Geschwindigkeit",
	"   Velocita",
    "   Snelheid"
};

const char MMSG_SETTING_SAVE[8][23] PROGMEM = {
	"    保存关机",
	"    Save&Off",
	"   印刷を保存",
	" Guardar impresión",
    "    Save&Off",
    "Speichern&Verlassen",
    " Salva e spegni",
    " Opslaan&Uitzetten"
};

const char MMSG_SETTING_FEED[8][22] PROGMEM = {
	"    自动进丝",
	"  Filament Feed",
	"  自動ワイヤ送り",
	"Entrada de filamento",
    " Charge filament",
	" Filament Zuführung",
	" Carica filamento",
    " Filament Invoer"
};

const char MMSG_SETTING_RETRACT[8][23] PROGMEM = {
	"    自动退丝",
	" Filament Retract",
	"  自動ワイヤ除去",
	"Salida de filamento",
    "Decharger le filament",
	" Filament Rückzug",
	" Scarica Filament",
    "Filament Terugvoer"
};

const char MMSG_SETTING_HEAT[8][16] PROGMEM = {
	"    手动加热",
	"    Preheat",
	"    予熱する",
	"   Precalentar",
    "   Préchauffer",
    "    Vorheizen",
    "  Preriscaldare",
    "    Opwarmen"
};

const char MMSG_SETTING_JOG[8][20] PROGMEM = {
	"    点动模式",
	"   Jog Mode",
	"   ジョグモード",
	"  Modo de jog",
    " Mode jogging",
    "Achsenbewegungen",
    "  Modalità Jog",
    "   Jog Modus"
};

const char MMSG_SETTING_LEVELBED[8][22] PROGMEM = {
	"    平台校准",
	"   Level Bed",
	"  レベルベッド",
	" Nivelar plataforma",
    "  Regl. Niv. lit",
	" Druckbett leveln",
	"  Livella piano",
    "  Afstellen Bed"
};

const char MMSG_SETTING_ZOFFSET[8][15] PROGMEM = {
	"    Z轴偏置",
	"   Z Offset",
	"   Zオフセット",
	"   Desfase Z",
    "  Decalage Z",
	" Z einstellen",
	"   Z Offset",
    "   Z Marge"
};

const char MMSG_SETTING_SENSOR[8][22] PROGMEM = {
	"接近开关高度调节",
	" Proximity Height",
	"   近接の高さ",
	"   Proximidad",
    "proximité Hauteur",
    " Proximity Hohe",
    "Proximity Altezza",
    "Hoogte-sensor Hoogte"
};
const char MMSG_SETTING_MOTOROFF[8][24] PROGMEM = {
	"    关闭电机",
	"   Motor Off",
	"  モーターを切る",
	"  Motor apagado",
    "  Moteur éteint",
    "Motoren deaktivieren",
    "  Motore spento",
    "   Motor Uit"
};

const char MMSG_SETTING_TITLE[8][25] PROGMEM = {
	"打印机参数设置",
	"Printer Setting",
	"プリンター設定",
	"Ajuste de parámetros",
    "Paramètre d'imprimante",
    "Drucker Einstellungen",
    "Impostazioni stampante",
    "Printer Instelling"
};

const char MMSG_SETTING_WIFI[8][20] PROGMEM = {
	"  Wifi网络设置",
	"   Wifi Setting",
	"  無線LAN設定",
	"   Red wifi",
    "  Réglage Wifi",
    "Wifi Einstellungen",
    " Wifi Impostazione",
    " WiFi Instelling"
};

const char MMSG_SETTING_POWEROFF[8][26] PROGMEM = {
	"  打印完成关机",
	" Auto Power Off",
	"  プリントオフ",
	"Apagado automático",
    "Arrêt automatique",
    "  Ausschalten",
    "Auto spegnimento",
    " Auto Power Off"
};

const char MMSG_SETTING_LANGUAGE[8][20] PROGMEM = {
	"    语言设置",
	" Language Setting",
	"    言語設定",
	"     Idioma",
    "     Langue",
    "Spracheinstellung",
    "    linguaggio",
    " Taal Instelling"
};

const char MMSG_SETTING_INFO[8][21] PROGMEM = {
	"    设备信息",
	"   Machine Info",
	"  デバイス情報",
	"   Informacion",
    "   Information",
	"Druckerinformation",
	"  Informazione",
    "  Machine Info"
};

const char MMSG_SETTING_RUNOUT[8][22] PROGMEM = {
	"    料丝检测",
	"  Runout Sensor",
	"  ワイヤー検出",
	"Sensor de filamento",
    "Capteur faux-rond",
    "  Filamentsensor",
    "  runout Sensor",
    " Filament Sensor"
};

const char MMSG_SETTING_SELFTEST[8][21] PROGMEM = {
	"    开机自检",
	"     Post",
	"  セルフテスト",
	"   Autoprueba",
    "     Publier",
    "Druckerselbsttest",
    "   Inviare",
    "   Zelftest"
};

const char MMSG_SETTING_POWERSAVE[8][26] PROGMEM = {
	"    节电模式",
	"Power Save Mode",
	"   節電モード",
	"Ahorro de energía",
    "Economie d'énergie",
    "Stromspareinstellung",
    "Risparmio energetico",
    "Energie Besparing Modus"
};

const char MMSG_SETTING_RESTORE[8][20] PROGMEM = {
	"    固件参数",
	"    Parameters",
	"    パラメータ",
	"    Parámetro",
    "   Paramètres",
    "   Parameter",
    "    Parametri",
    "   Parameters"
};

const char MMSG_SETTING_IAP[8][20] PROGMEM = {
	"    升级固件",
	"    Update",
	"    更新する",
	"  Actualización",
    "  Mettre à jour",
    "    Update",
    "   Aggiornare",
    "    Update"
};

const char MMSG_STATUS_TITLE_PRINTING[8][16] PROGMEM = {
	"正在打印",
	"Printing",
	"印刷",
	"Impresión",
    "Impression",
	"Drucke",
	"Stampa",
    "Printen"
};

const char MMSG_STATUS_TITLE_PAUSE[8][20] PROGMEM = {
	"打印暂停",
	"Print Pause",
	"印刷一時停止",
	"Pausa de impresión",
    "Imprimer Pause",
    "Druckpause",
    "Stampa Pausa",
    "Print Pause"
};

const char MMSG_STATUS_LABEL_FILE[8][9] PROGMEM = {
	"文件",
	"File",
	"ファイル",
	"Archivo",
    "Fichier",
    "Datei",
    "File",
    "Bestand"
};

const char MMSG_STATUS_LABEL_SPEED[8][19] PROGMEM = {
	"打印速度",
	"Speed",
	"印刷速度",
	"Velocidad",
    "Vitesse",
	"Geschwindigkeit",
	"Velocita",
    "Snelheid"
};

const char MMSG_STATUS_LABEL_NOZZLE1[8][10] PROGMEM = {
	"左喷头",
	"Left",
	"左ノズル",
	"Izquierdo",
	"La gauche",
	"links",
	"Sinistra",
    "Links"
};

const char MMSG_STATUS_LABEL_NOZZLE2[8][10] PROGMEM = {
	"右喷头",
	"Right",
	"右ノズル",
	"Derecho",
	"Droit",
	"rechts",
	"Destro",
    "Rechts"
};

const char MMSG_STATUS_LABEL_BED[8][12] PROGMEM = {
	"平台温度",
	"Bed",
	"ベッド",
	"Cama",
    "Lit",
	"Druckbett",
	"Piatto",
    "Bed"
};

const char MMSG_STATUS_LABEL_ELAPSED[8][15] PROGMEM = {
	"已用时间",
	"Elapsed",
	"経過",
	"Transcurrido",
    "Ecoulé",
    "abgelaufen",
    "Trascorso",
    "Verstreken"
};

const char MMSG_STATUS_LABEL_REMAIN[8][15] PROGMEM = {
	"剩余时间",
	"Remain",
	"残ります",
	"Permanecer",
    "Rester",
    "verbleibend",
    "Rimani",
    "Resterend"
};

const char MMSG_STATUS_LABEL_PERCENT[8][13] PROGMEM = {
	"打印进度",
	"Percent",
	"パーセント",
	"Por ciento",
    "Pour cent",
    "Prozent",
    "Per cento",
    "Percentage"
};

const char MMSG_EXIT[8][11] PROGMEM = {
	"  退出",
	"  Quit",
	" 終了する",
	"  Dejar",
    "Quitter",
	" Beenden",
	"Smettere",
    "  Stop"
};

const char MMSG_PAUSE[8][10] PROGMEM = {
	"  暂停",
	"  Pause",
	" 一時停止",
	"  Pausa",
    "  Pause",
    "  Pause",
    "  Pausa",
    "  Pause"
};

const char MMSG_RESUME[8][12] PROGMEM = {
	"  继续",
	"  Resume",
	"  続ける",
	"  Continuar",
    "  Résumé",
    " Fortsetzen",
    "  Riprendi",
    "  Hervat"
};

const char MMSG_SETTING[8][15] PROGMEM = {
	"  设置",
	" Setting",
	"  設定",
	" Ajuste",
    " Réglage",
    " Einstellung",
    "Ambientazione",
    " Instelling"
};

const char MMSG_YES[8][7] PROGMEM = {
	"  确定",
	"  YES",
	"  はい",
	"  Si",
    "  OUI",
    "  JA",
    "  Si",
    "  JA"
};

const char MMSG_NO[8][8] PROGMEM = {
	"  取消",
	"  NO",
	" いいえ",
	"  NO",
    "  NON",
    " NEIN",
    "  NO",
    "  NEE"
};

const char MMSG_PRINTINT_SETTING_TITLE[8][30] PROGMEM = {
	"打印参数设置",
	"Printing Setting",
	"印刷設定",
	"Configuración de impresión",
    "Paramètres d'impression",
    "Druckeinstellungen",
    "Impostazioni di stampa",
    "Print Instelling"
};

const char MMSG_CONFIRM_TITLE[8][13] PROGMEM = {
	"确认",
	"Confirm",
	"確認する",
	"Confirmar",
    "Confirmer",
    "Bestatigen",
    "Confermare",
    "Bevestig"
};

const char MMSG_QUIT_PRINT_CONFIRM_TEXT[8][166] PROGMEM = {
	"\r\n\r\n 当前打印任务将中止，并且不可恢复。\r\n 你确定要退出吗?",
	"\r\n\r\nThe current print job will be aborted and\r\ncannot be recovered.\r\nAre you sure you want to quit?",
	"\r\n\r\n現在の印刷ジョブは中止され,回復することはでき\r\nません.\r\n本当にやめる気?",
	"\r\n\r\nEl trabajo de impresión actual se cancelará y no se podrá recuperar.\r\nSeguro que quieres salir?",
    "\r\n\r\nLe travail d'impression en cours sera abandonné et ne pourra pas être récupéré.\r\nEtes-vous sur de vouloir quitter?",
    "\r\n\r\nDer aktuelle Druck wird abgebrochen und kann danach nicht wieder aufgenommen werden!\r\nSind Sie sicher, dass Sie den Druck wirklich abbrechen wollen?",
    "\r\n\r\nIl lavoro di stampa corrente verrà interrotto e non potrà essere ripristinato.\r\nSei sicuro di voler uscire?",
    "\r\n\r\nDe huidige printtaak wordt gestopt en kan niet worden hervat.\r\nWeet je zeker dat je wilt stoppen?"
};

const char MMSG_FILAMENT_OPERATION_TITLE[8][30] PROGMEM = {
	"料丝操作",
	"Filament Operation",
	"フィラメント操作",
	"Operación del filamento",
    "Fonctionnement du filament",
    "Filamenteinstellungen",
    "Funzionamento del filamento",
    "Filament Werking"
};

const char MMSG_OK[8][12] PROGMEM = {
	"  确定",
	"  OK",
	"  OK",
	"DE ACUERDO",
    " D'accord",
    "  OK",
    "  ok",
    "  OK"
};

const char MMSG_CANCEL[8][12] PROGMEM = {
	"  取消",
	" Cancel",
	" キャンセル",
	" Cancelar",
    " Annuler",
    " Abbruch",
    " Annulla",
    " Annuleer"
};

const char MMSG_PREHEAT_TITLE[8][42] PROGMEM = {
	"设置目标温度",
	"Set Target Temperature",
	"目標温度を設定する",
	"Ajustar la temperatura objetivo",
    "Définir la température cible",
    "gewünschte Ziel-Temperatur einstellen",
    "Imposta la temperatura target",
    "Stel Doel Temperatuur in"
};

const char MMSG_ERROR_MINTEMP[8][54] PROGMEM = {
	"喷头故障: 无法读取到有效温度, 请检查喷头接口",
	"Nozzle failure: temperature can't be read",
	"ノズル故障: 温度が読めない",
	"Fallo de la boquilla: error de temperatura",
    "Panne de buse: la température ne peut pas être lue",
    "Düsenfehler: Temperatur kann nicht ermittelt werden",
    "Guasto ugello: impossibile leggere la temperatura",
    "Printkop fout: temperatuur kan niet worden afgelezen"
};

const char MMSG_ERROR_BEDTEMP[8][60] PROGMEM = {
	"热床故障: 无法读取到有效温度, 请检查热床接口",
	"Bed failure: temperature can't be read",
	"ベッド不良: 温度が読み取れない",
	"Falla de cama: la temperatura no se puede leer",
    "Panne du lit: la température ne peut pas être lue",
    "Heizbettfehler: Temperatur kann nicht ermittelt werden",
    "Guasto al letto: impossibile leggere la temperatura",
    "Bed fout: temperatuur kan niet worden afgelezen"
};

const char MMSG_ERROR_MAXTEMP[8][68] PROGMEM = {
	"喷头故障: 温度超过有效范围",
	"Nozzle failure: temperature exceeds maximum",
	"ノズルの故障: 温度が最高値を超えています",
	"Fallo de la boquilla: temperatura demasiado alta",
    "Panne de buse: la température dépasse le maximum",
    "Düsenfehler: Temperatur übersteigt den zulassigen Hochstwert!",
    "Guasto ugello: la temperatura supera il massimo",
    "Printkop fout: temperatuur hoger dan toegestaan"
};

const char MMSG_FILAMENT_TYPE_NAME1[4] PROGMEM = {
	"PLA"
};

const char MMSG_FILAMENT_TYPE_NAME2[4] PROGMEM = {
	"ABS"
};

const char MMSG_FILAMENT_TYPE_NAME4[10] PROGMEM = {
	"TPU 240℃"
};

const char MMSG_FILAMENT_TYPE_NAME3[8][19] PROGMEM = {
	"高温料丝",
	"Other Filament",
	"その他の",
	"Otro filamento",
    "Autre filament",
    "Anderes Filament",
    "Altro",
    "Ander Filament"
};
const char MMSG_FILAMENT_TYPE_TEMP1[8] PROGMEM = {
	"210℃"
};

const char MMSG_FILAMENT_TYPE_TEMP2[8] PROGMEM = {
	"235℃"
};

const char MMSG_FILAMENT_TYPE_TEMP3[8] PROGMEM = {
	"260℃"
};

const char MMSG_FILAMENT_TYPE_TEMP4[6] PROGMEM = {
	"240℃"
};

const char MMSG_FILAMENT_TYPE_TITLE[8][30] PROGMEM = {
	"选择料丝类型 ",
	"Filament Type ",
	"フィラメントの種類",
	"Tipo de filamento ",
    "Type de filament",
    "Filamenttyp",
    "Tipo di filamento",
    "Filament Type"
};



const char MMSG_FILAMENT_LEFT_IN_TITLE[8][34] PROGMEM = {
	"左喷头自动进丝",
	"Left Nozzle Filament Feed",
	"自動ワイヤ送り",
	"Boquilla izquierda Feedin",
    "Alimentation de la buse gauche",
    "Filament laden linke Düse",
    "Alimentazione ugello sinistro",
    "Linker Printkop Filament Invoer"
};

const char MMSG_FILAMENT_RIGHT_IN_TITLE[8][35] PROGMEM = {
	"右喷头自动进丝",
	"Right Nozzle Filament Feed",
	"自動ワイヤ送り",
	"Boquilla derecha Feedin",
    "Alimentation de la buse droite",
    "Filament laden rechte Düse",
    "Alimentazione ugello destro",
    "Rechter Printkop Filament Invoer"
};

const char MMSG_FILAMENT_LEFT_OUT_TITLE[8][35] PROGMEM = {
	"左喷头自动退丝",
	"Left Nozzle Filament Retract",
	"自動ワイヤ除去",
	"Boquilla izquierda retraída",
    "Rétractation de la buse gauche",
    "Filamententladen linke Düse",
    "Retrazione ugello sinistro",
    "Linker Printkop Filament Uitvoer"
};

const char MMSG_FILAMENT_RIGHT_OUT_TITLE[8][35] PROGMEM = {
	"右喷头自动退丝",
	"Right Nozzle Filament Retract",
	"自動ワイヤ除去",
	"Boquilla derecha retraída",
    "Rétracter la buse droite",
    "Filament entladen rechte Düse",
    "Retrazione ugello destro",
    "Rechter Printkop Filament Uitvoer"
};

const char MMSG_FILAMENT_IN_TITLE[8][22] PROGMEM = {
	"自动进丝",
	"Filament Feed",
	"自動ワイヤ送り",
	"Entrada de filamento",
    "Charge filament",
	"Filament laden",
	"Carica filamento",
    "Filament Invoer"
};

const char MMSG_FILAMENT_OUT_TITLE[8][22] PROGMEM = {
	"自动退丝",
	"Filament Retract",
	"自動ワイヤ除去",
	"Salida de filamento",
    "Decharger le filament",
	"Filament entladen",
	"Scarica Filament",
    "Filament Uitvoer"
};

const char MMSG_FILAMENT_IN_LINE1[8][18] PROGMEM = {
	"正在加热...",
	"Heating...",
	"加熱...",
	"Calefacción",
    "Chauffage...",
    "Aufheizen...",
    "Riscaldamento...",
    "Opwarmen..."
};

const char MMSG_FILAMENT_IN_LINE2[8][66] PROGMEM = {
	"请将料丝插入挤出器模块，然后稍等片刻",
	"Insert the filament and wait a while",
	"フィラメントを挿入してしばらく待ちます",
	"Insertar el filamento y esperar un rato",
    "Insérez le filament et attendez un moment",
    "Führen Sie das Filament ein und warten Sie dann einen Moment",
    "Inserisci il filamento e attendi qualche istante",
    ""
};

const char MMSG_FILAMENT_OUT_LINE2[8][37] PROGMEM = {
	"请稍等",
	"Please wait a few minutes",
	"数分お待ちください",
	"Por favor espere unos minutos",
    "Veuillez patienter quelques minutes",
    "Bitte warten Sie ein paar Minuten",
    "Attendi qualche minuto",
    "Enkele minuten geduld a.u.b."
};

const char MMSG_FILAMENT_IN_LINE3[8][36] PROGMEM = {
	"正在进丝...",
	"Filament feeding...",
	"フィラメント送り...",
	"Filamento de alimentación",
    "Alimentation en filament...",
    "Lade Filament...",
    "Alimentazione del filamento...",
    "Filament invoeren..."
};

const char MMSG_FILAMENT_OUT_LINE3[8][32] PROGMEM = {
	"正在退丝...",
	"Filament retracting...",
	"フィラメント収縮中...",
	"Filamento de retracción ...",
    "Alimentation en filament...",
    "Entlade Filament...",
    "Alimentazione del filamento...",
    "Filament uitvoeren..."
};

const char MMSG_HEATING_TITLE[8][15] PROGMEM = {
	"正在加热",
	"Heating",
	"加熱",
	"Calefacción",
    "Chauffage",
    "Aufheizen",
    "Riscaldamento",
    "Opwarmen"
};

const char MMSG_JOB_TITLE[8][22] PROGMEM = {
	"点动模式",
	"Jog Mode",
	"ジョグモード",
	"Modo de jog",
    "Mode jogging",
    "Achsenbewegungen",
    "Modalità Jog",
    "Jog Modus"
};

const char MMSG_RETURN_HOME[8][20] PROGMEM = {
	"   返回原点",
	" Return Home",
	"  原点に戻る",
	"Volver a origen",
    "   Accueil",
    "   Zuhause",
    " Torna a casa",
    "  Keer Terug"
};

const char MMSG_LEVEL_TITLE[8][32] PROGMEM = {
	"Delta自动校准",
	"Delta Auto Calibration",
	"デルタ自動校正",
	"Delta Auto Calibration",
	"Etalonnage automatique Delta",
	"Delta Auto Calibration",
	"Calibrazione automatica delta",
    "Delta automatische kalibratie"
};

const char MMSG_BEGIN[8][10] PROGMEM = {
	"  开始",
	"  Begin",
	"  ベギン",
	" Comenzar",
    "Commencer",
    "  Start",
    "  Inizio",
    "  Begin"
};

const char MMSG_END[8][10] PROGMEM = {
	"  结束",
	"  End",
	" 終わり",
	" Final",
    "  Fin",
    "  Ende",
    "  Fine",
    "  Eind"
};

const char MMSG_NEXT[8][12] PROGMEM = {
	"  下一步",
	"  Next",
	"  次",
	" Siguiente",
    "Continuer",
	"Fortfahren",
	"Continua",
    " Volgende"
};

const char MMSG_LEVEL0_LINE1[8][230] PROGMEM = {
	"平台校准是以喷头为基准, 依次测量并调节平台4个点与喷头的间隙,确保打印平台平行于喷头工作平台.\r\n准备一张白纸后开始.",
	"Level Bed is to measure and adjust the gap between the 4 points of the platform and the nozzle.\r\nPrepare a paper and begin.",
	"レベルベッドは, プラットフォームとノズルの4点間のギャップを測定し調整することです.\r\n紙を用意して始めます.",
	"La cama nivelada es para medir y ajustar el espacio entre los 4 puntos de la plataforma y la boquilla.\r\nPreparar un papel y comenzar.",
    "Level Bed permet de mesurer et d'ajuster l'écart entre les 4 points de la plateforme et la buse.\r\nPréparez un papier et commencez.",
    "Das Druckbett wird gelevelt um den Abstand zwischen den 4 Eckpunkten der Druckplattform und der Düse korrekt einzustellen.\r\nHalten Sie ein Blatt normales (Schreib)Papier bereit und starten Sie dann den Vorgang.",
    "Level Bed serve per misurare e regolare la distanza tra i 4 punti della piattaforma e la bocchetta.\r\nPrepara un foglio e inizia.",
    "Level Bed is om de afstand tussen het printbed en de printkop of 4 plaatsten te meten en in te stellen.\r\nNeem een stuk papier en begin."
};

const char MMSG_LEVEL1_LINE1[8][250] PROGMEM = {
	"调节平台右后方的螺母,直至喷头与平台的间隙为一张纸的厚度.\r\n完成后点下一步.",
	"Adjust the nut on the right rear of the bed, until the gap is the thickness of a piece of paper.\r\nClick Next to continue.",
	"隙間が一枚の紙の厚さになるまで,ベッドの右後部にあるナットを調整します.\r\n次へをクリックして続けます.",
	"Ajustar la tuerca en la parte posterior derecha de la cama, hasta que el espa cio es el grosor de una hoja de papel Haga clic en Siguiente para continuar.",
    "Ajustez l'écrou à l'arrière droit du lit, jusqu'à ce que l'écart soit de l'épaisseur d'un morceau de papier.\r\nCliquer sur Suivant pour continuer.",
    "Bewegen Sie das Papier zwischen Düse und Druckbett. Wahrenddessen verstellen Sie die hintere rechte Einstellschraube (unter dem Druckbett), bis die Düse gerade eben spürbar das Blatt Papier berührt.\r\nKlicken Sie danach auf Fortfahren.",
    "Regola il dado sul retro destro del letto, fino a quando lo spazio non è lo spessore di un pezzo di carta.\r\nFare clic su Avanti per continuare.",
    "Pas de schroef aan de rechter achterzijde van het printbed aan totdat het de afstand gelijk is aan de dikte van het papier.\r\nKlik Volgende om verder te gaan."
};

const char MMSG_LEVEL2_LINE1[8][250] PROGMEM = {
	"调节平台左后方的螺母,直至喷头与平台的间隙为一张纸的厚度.\r\n完成后点下一步.",
	"Adjust the nut on the left rear of the bed, until the gap is the thickness of a piece of paper.\r\nClick Next to continue.",
	"隙間が一枚の紙の厚さになるまで, ベッドの左後部にあるナットを調整します.\r\n次へをクリックして続けます.",
	"Ajustar la tuerca en la parte posterior izquierda de la cama, hasta que el esp acio es el grosor de una hoja de pap el. Haga clic enSiguiente para continuar",
    "Ajustez l'écrou sur l'arrière gauche du lit, jusqu'à ce que l'écart soit l'épaisseur d'un morceau de papier.\r\nCliquer sur Suivant pour continuer.",
    "Bewegen Sie das Papier zwischen Düse und Druckbett. Wahrenddessen verstellen Sie die hintere linke Einstellschraube (unter dem Druckbett), bis die Düse gerade eben spürbar das Blatt Papier berührt.\r\nKlicken Sie danach auf Fortfahren.",
    "Regola il dado sulla parte posteriore sinistra del letto, finché lo spazio non è dello spessore di un pezzo di carta.\r\nFare clic su Avanti per continuare.",
    "Pas de schroef aan de linker achterzijde van het printbed aan totdat het de afstand gelijk is aan de dikte van het papier.\r\nKlik Volgende om verder te gaan."
};

const char MMSG_LEVEL3_LINE1[8][250] PROGMEM = {
	"调节平台左前方的螺母,直至喷头与平台的间隙为一张纸的厚度.\r\n完成后点下一步.",
	"Adjust the nut on the left front of the bed, until the gap is the thickness of a piece of paper.\r\nClick Next to continue.",
	"隙間が一枚の紙の厚さになるまで,ベッドの左前面にあるナットを調整します.\r\n次へをクリックして続けます.",
	"Ajustar la tuerca enla parte frontal iz quierda de la cama, hasta que el espa cio es el grosor de una hoja de papel Haga clic en Siguiente para continuar.",
    "Ajustez l'écrou sur l'avant gauche du lit, jusqu'à ce que l'écart soit l'épaisseur d'un morceau de papier.\r\nCliquer sur Suivant pour continuer.",
    "Bewegen Sie das Papier zwischen Düse und Druckbett. Wahrenddessen verstellen Sie die vordere linke Einstellschraube (unter dem Druckbett), bis die Düse gerade eben spürbar das Blatt Papier berührt.\r\nKlicken Sie danach auf Fortfahren.",
    "Regola il dado sulla parte anteriore sinistra del letto, finché lo spazio non è dello spessore di un pezzo di carta.\r\nFare clic su Avanti per continuare.",
    "Pas de schroef aan de linker voorzijde van het printbed aan totdat het de afstand gelijk is aan de dikte van het papier.\r\nKlik Volgende om verder te gaan."
};

const char MMSG_LEVEL4_LINE1[8][270] PROGMEM = {
	"调节平台右前方的螺母,直至喷头与平台的间隙为一张纸的厚度.\r\n完成后结束平台校准.",
	"Adjust the nut on the right front of the bed, until the gap is the thickness of a piece of paper.\r\nClick End to finish Level Bed.",
	"隙間が一枚の紙の厚さになるまで, ベッドの右前面にあるナットを調整します. 終わりをクリックしてレ",
	"Ajustar la tuerca en la parte frontal derecha de la cama, hasta que el espa cio es el grosor de una hoja de papel Haga clic en Finalizar para finalizar.",
    "Ajustez l'écrou sur le devant droit du lit, jusqu'à ce que l'écart soit l'épaisseur d'un morceau de papier.\r\nCliquez sur Fin pour terminer le lit de niveau.",
    "Bewegen Sie das Papier zwischen Düse und Druckbett. Wahrenddessen verstellen Sie die vordere rechte Einstellschraube (unter dem Druckbett), bis die Düse gerade eben spürbar das Blatt Papier berührt.\r\nKlicken Sie danach auf Ende um den Vorgang abzuschlieben.",
    "Regola il dado sulla parte anteriore destra del letto, finché lo spazio non è lo spessore di un pezzo di carta.\r\nFare clic su Fine per terminare Level Bed.",
    "Pas de schroef aan de rechter voorzijde van het printbed aan totdat het de afstand gelijk is aan de dikte van het papier.\r\nKlik Volgende om verder te gaan."
};

const char MMSG_NOTICE_MOVING[8][52] PROGMEM = {
	"\r\n\r\n 正在移动, 请稍等...",
	"\r\n\r\n Moving, please wait...",
 	"\r\n\r\n 移動しています,お待ちください...",
	"\r\n\r\n En movimiento, por favor espere...",
    "\r\n\r\n Déménagement, veuillez patienter...",
    "\r\n\r\n Führe Achsbewegung aus, bitte warten...",
    "\r\n\r\n Trasloco, attendere prego...",
    "\r\n\r\nAan het verplaatsen, even geduld..."
};

const char MMSG_ZOFFSET_TITLE[8][35] PROGMEM = {
	"Z轴偏置设置",
	"Z Offset Setting",
	"Zオフセット設定",
	"Ajuste de compensación de Z",
    "Réglage du décalage Z",
    "Z-Versatz (Offset) Einstellung",
    "Impostazione offset Z",
    "Z Marge Instelling"
};

const char MMSG_SAVE[8][10] PROGMEM = {
	"  保存",
	"  Save",
	" 保存する",
	" Guardar",
    " sauver",
    "Speichern",
    " Salva",
    " Opslaan"
};

const char MMSG_ZOFFSET_LINE[8][440] PROGMEM = {
	"Z轴偏置用于微调喷头与平台的间隙.\r\n准备一张纸片置于喷头下. 点击按钮上下微动平台, 直至间隙为一张纸的厚度.\r\n完成后点击保存退出.",
	"The Z-axis offset is used to tune the gap between thenozzle and the platform. Prepare a piece of paper to beplaced under the nozzle. Click the button to move the\r\nplatform up and down until the gap is the thickness of a piece of paper. Click after finishing Save and exit.",
	"Z軸オフセットを使用して, ノズルとプラットフォーム間のギャップを微調整します. ノズルの下に配置する紙を準備します. ボタンをクリックして, ギャップが紙の厚さになるまでプラットフォームを上下に移動します. \r\n終了したら、[保存]をクリックして終了します.",
	"eje Z desplazamiento de recorte para la boquilla hueco y la plataforma. Preparar una hoja de papel colocado bajo la cabeza. Haga clic en la mesa de movimiento fino vertical, un espesor de la brecha hasta una hoja de papel. Cuando termine, haga clic en Guardar para salir.",
    "Le décalage de l'axe Z est utilisé pour régler l'écart entre la buse et la plate-forme. Préparez un morceau de papier à placer sous la buse. Cliquez sur le bouton pour déplacer la plate-forme vers le haut et vers le bas jusqu'à ce que l'espace ait la même épaisseur qu'un morceau de papier. Cliquez après avoir terminé Enregistrer et quitter.",
    "Die Einstellung des Z-Versatzes (Offset) ist notig, um den Abstand zwischen Düse und Druckplattform genau abzustimmen. Bereiten Sie ein Blatt normales (Schreib)Papier vor, welches Sie zwischen Düse und Druckbett positionieren. Drücken Sie anschliebend die entsprechende Schaltflache, um die Düse auf und ab zu bewegen, bis der Abstand gerade die Dicke des Papiers hat.  Wenn Sie fertig sind klicken Sie auf Speichern und Schlieben.",
    "L'offset dell'asse Z viene utilizzato per regolare la distanza tra l'ugello e la piattaforma. Preparare un foglio di carta da posizionare sotto la bocchetta. Fare clic sul pulsante per spostare la piattaforma su e giù fino a quando lo spazio è lo spessore di un pezzo di carta. Fare clic dopo aver terminato Salva ed esci.",
    "De Z-as marge wordt gebruikt om de afstand tussen de printkop en het printbed te fine tunen. Gebruik een stukje normaal printpapier om onder de printkop te schuiven.\r\nGebruik de knoppen om de hoogte aan te passen totdat de afstand tussen printkop en printbed gelijk is aan de dikte van het papier. Daarna Opslaan en Afsluiten."
};

const char MMSG_MOTOROFF_LINE1[8][55] PROGMEM = {
	"\r\n\r\n 所有电机输出已关闭",
	"\r\n\r\n All motor outputs are off.",
	"\r\n\r\n すべてのモーター出力はオフです.",
	"\r\n\r\n Todas las salidas del motor están apagadas.",
    "\r\n\r\n Toutes les sorties moteur sont désactivées.",
    "\r\n\r\n Alle Motoren sind deaktiviert.",
    "\r\n\r\n Tutte le uscite del motore sono disattivate.",
    "\r\n\r\nAlle motor outputs zijn uitgeschakeld."
};

const char MMSG_POXIMITY_TITLE[8][40] PROGMEM = {
	"接近开关高度调节",
	"Proximity Height Adjustment",
 	"近接センサーの高さ調整",
	"Ajuste de altura de proximidad",
    "Réglage de la hauteur de proximité",
    "Hohenjustierung des Annaherungssensors",
    "Regolazione dell'altezza di prossimità",
    "Hoogte-sensor Hoogte Aanpassing"
};

const char MMSG_POXIMITY_LINE[8][250] PROGMEM = {
	"平台停止运行后, 接近开关应该为导通状态. 如果开关为断开状态, 请松开固定接近开关的螺丝, 向下微调接近开关高度, 直至开关导通. 然后拧紧螺丝固定好接近开关.\r\n接近开关当前状态:",
	"After moving, the proximity should be on. If it is off, loosen the screw and fine-tune the height of proximity, until the switch is turned on. Then fix the position of proximity.\r\nCurrent status is:",
 	"移動した後, 近接がオンになっているはずです. オフになっている場合は,スイッチがオンになるまでネジを緩め,近接の高さを微調整します. 次に近接位置を固定します.\r\n現在の状況は以下のとおりです:",
	"Después de mover, la proximidad debe estar en. De lo contrario, afloje el tornillo y ajuste la altura de proximidad hasta que se encienda el interruptor. Entonces arréglalo. \r\nEl estado actual es:",
    "Après le déplacement, la proximité doit être activée. S'il est éteint, desserrez la vis et ajustez la hauteur de proximité, jusqu'à ce que l'interrupteur soit allumé. Fixez ensuite la position de proximité.\r\nL'état actuel est:",
    "Nach der Bewegung sollte der Annaherungssensor AN sein. Wenn er AUS ist, lockern Sie die Schraube und andern die Hohe des Sensors bis der Status unten auf AN springt. Danach fixieren Sie die Schraube wieder. Der aktuelle Status ist:",
    "Dopo lo spostamento, la prossimità dovrebbe essere attiva. Se è spento, allentare la vite e regolare con precisione l'altezza di prossimità, fino a quando l'interruttore è acceso. Quindi fissare la posizione di prossimità. Lo stato attuale è:",
    "Na het bewegen zoud de hoogte-sensor aan moeten staan. Als deze uitstaat, draai de schroef los en pas de hoogte aan. de hoogte van de sensor, totdat deze aangaat.\r\nZet de sensor nu weer vast. De status is:"
};

const char MMSG_SWITCH_ON[8][7] PROGMEM = {
	"导通",
	"ON",
 	"に",
	"ON",
    "SUR",
    "AU",
    "SOPRA",
    "AAN"
};

const char MMSG_SWITCH_OFF[8][5] PROGMEM = {
	"断开",
	"OFF",
 	"オフ",
	"OFF",
    "DE",
    "AUS",
    "OFF",
    "UIT"
};

const char MMSG_MACHINE_TITLE[8][30] PROGMEM = {
	"设备信息",
	"Machine Information",
 	"マシン情報",
	"Información de la máquina",
    "Informations sur la machine",
    "Gerateinformationen",
    "Informazioni sulla macchina",
    "Machine Informatie"
};

const char MMSG_MACHINE_ITEM1[8][26] PROGMEM = {
	"设备名称",
	"Device Name",
 	"装置名:",
	"Nombre del dispositivo",
    "Nom de l'appareil",
    "Geatename",
    "Nome del dispositivo",
    "Apparaat Naam"
};

const char MMSG_MACHINE_ITEM2[8][18] PROGMEM = {
	"已打印时间",
	"Printed Time",
 	"印刷された時間",
	"Hora impresa",
    "Temps imprimé",
    "Druckzeit",
    "Tempo stampato",
    "Totale Printtijd"
};

const char MMSG_MACHINE_ITEM3[8][23] PROGMEM = {
	"固件版本",
	"Firmware Version",
 	"ファームウェア",
	"Versión de firmware",
    "Version du firmware",
    "Firmwareversion",
    "Versione del firmware",
    "Firmware versie"
};

const char MMSG_MACHINE_ITEM4[8][16] PROGMEM = {
	"UI版本",
	"UI Version",
 	"UIのバージョン",
	"UI",
    "UI Version",
    "UI-Version",
    "UI Version",
    "UI Versie"
};

const char MMSG_MACHINE_ITEM5[8][25] PROGMEM = {
	"设备序列号",
	"Device Serial",
 	"デバイスシリアル",
	"Serie del dispositivo",
    "Série de l'appareil",
    "Seriennummer",
    "Seriale del dispositivo",
    "Serienummer"
};

const char MMSG_MACHINE_ITEM6[8][20] PROGMEM = {
	"WIFI设备名称",
	"WIFI Device",
 	"WIFIデバイス",
	"Dispositivo wifi",
    "Dispositif WIFI",
    "WIFI-Gerat",
    "Dispositivo WIFI",
    "WiFi Apparaat"
};

const char MMSG_WIFISETTING_TITLE[8][20] PROGMEM = {
	"Wifi网络设置",
	"Wifi Setting",
	"無線LAN設定",
	"Red wifi",
    "Paramètres Wifi",
    "WiFi Einstellung",
    "Impostazione Wi-Fi",
    "WiFI Instelling"
};

const char MMSG_WIFISETTING_CONNECT[8][20] PROGMEM = {
	"  连接Wifi网络",
	"  Connect Wifi",
	"   Wifiを接続",
	"  Conectar wifi",
    "Connectez le Wifi",
    " Wifi-Verbindung",
    "Connetti Wifi",
    "  Verbind WiFi"
};

const char MMSG_WIFI_INFO_TITLE[8][26] PROGMEM = {
	"WIFI设备信息",
	"WIFI Device Information",
 	"WIFIデバイス情報",
	"Información wifi",
    "Informations WIFI",
    "WiFi-Gerateinformation",
    "Informazioni WIFI",
    "WiFi Apparaat Informatie"
};


const char MMSG_WIFI_INFO_IP[8][14] PROGMEM = {
	"IP地址",
	"IP Address",
 	"IPアドレス",
	"IP WIFI",
    "Adresse IP",
    "IP Addresse",
    "Indirizzo IP",
    "IP Adres"
};

const char MMSG_WIFI_INFO_AP[8][16] PROGMEM = {
	"AP",
	"AP",
 	"AP",
	"AP",
    "AP",
    "Accesspoint",
    "AP",
    "AP"
};

const char MMSG_WIFI_INFO_CLOUD[8][21] PROGMEM = {
	"云连接",
	"Cloud Connection",
	"クラウド接続",
	"Conexión a la nube",
    "Connexion au cloud",
    "Cloud Verbindung",
    "Connessione cloud",
    "Cloud Verbinding"
};

// const char MMSG_WIFI_OTA[8][30] PROGMEM = {
// 	"在线升级WIFI设备固件",
// 	"Update WIFI Firmware Online",
//  	"WIFIファームウェアOTA",
// 	"Firmware WIFI OTA",
// };

const char MMSG_PRINTEND_TITLE[8][22] PROGMEM = {
	"打印完成",
	"Print Completed",
 	"印刷完了",
	"Imprimir Completado",
    "Impression terminée",
    "Druck abgeschlossen",
    "Stampa completata",
    "Print Afgerond"
};

const char MMSG_PRINTEND_FILE[8][22] PROGMEM = {
	"文件名:",
	"Filename:",
 	"ファイル名:",
	"Nombre del archivo:",
    "Nom de fichier:",
    "Dateiname:",
    "Nome del file:",
    "Bestandsnaam:"
};

const char MMSG_PRINTEND_TIME[8][22] PROGMEM = {
	"打印时间:",
	"Print Time:",
 	"印刷時間:",
	"Tiempo de impresión:",
    "Temps d'impression:",
    "Druckdauer:",
    "Tempo di stampa:",
    "Print Tijd:"
};

const char MMSG_PRINTEND_FILAMENT[8][26] PROGMEM = {
	"使用料丝:",
	"Using Filament:",
 	"フィラメントを使う",
	"Utilizando filamento",
    "Utilisation du filament:",
    "Filamentverbrauch:",
    "Utilizzo del filamento:",
    "Gebruikt Filament:"
};

const char MMSG_PRINTEND_AGAIN[8][21] PROGMEM = {
	"  再次打印",
	" Print Again",
 	" もう一度印刷",
	"Imprimir de nuevo",
    "Imprimer à nouveau",
    " erneut drucken",
    "Stampa di nuovo",
    " Print Opnieuw"
};

const char MMSG_POWEROFF_TITLE[8][46] PROGMEM = {
	"准备关机",
	"Prepare Poweroff",
 	"電源オフを準備する",
	"Preparar el apagado",
    "Préparer la mise hors tension",
    "Druckerabschaltung (Poweroff) vorbereiten",
    "Preparare lo spegnimento",
    "Uitzetten Voorbereiden"
};

const char MMSG_POWEROFF_LINE1[8][55] PROGMEM = {
	"正在准备关闭打印机.",
	"Preparing to turn off the printer.",
 	"プリンタの電源を切る準備をしています.",
	"Preparando para apagar la impresora.",
    "Préparation de la mise hors tension de l'imprimante.",
    "Bereite Abschaltung des Druckers vor",
    "Preparazione per spegnere la stampante.",
    "Voorbereiden om de printer uit te zetten"
};

const char MMSG_POWEROFF_LINE2[8][45] PROGMEM = {
	"剩余时间:",
	"Remaining time:",
 	"残り時間:",
	"Tiempo restante:",
    "Temps restant:",
    "verbleibende Zeit bis zur Abschaltung:",
    "Tempo rimanente:",
    "Resterende Tijd:"
};

const char MMSG_RESTORE_SETTING_LINE[8][99] PROGMEM = {
	"\r\n\r\n  确定要恢复出厂设置吗?",
	"\r\n\r\n  Are you sure to restore the factory settings?",
 	"\r\n\r\n  工場出荷時の設定に戻しますか?",
	"\r\n\r\n Estás seguro de restaurar a la predeterminada?",
    "\r\n\r\n Etes-vous sur de vouloir restaurer les paramètres d'usine?",
    "\r\n\r\n  Sind Sie sicher, dass Sie den Drucker auf Werkseinstellungen zurücksetzen mochten?",
    "\r\n\r\n Sei sicuro di ripristinare le impostazioni di fabbrica?",
    "\r\n\r\nBen je zeker dat je de fabrieksinstellingen wilt terugzetten?"
};

const char MMSG_SPEED_SETTING_TITLE[8][40] PROGMEM = {
	"打印速度设置",
	"Print Speed Setting",
 	"印刷速度設定",
	"Ajuste de velocidad",
    "Réglage de la vitesse d'impression",
    "Einstellung der Druckgeschwindigkeit",
    "Impostazione della velocità di stampa",
    "Print Snelheid Instelling"
};

const char MMSG_POWER_SAVE_TITLE[8][70] PROGMEM = {
	"自动关闭电源设置",
	"Auto Power Off Setting",
 	"オートパワーオフ設定",
	"Ajuste de apagado automático",
    "Réglage de la mise hors tension automatique",
    "Einstellung zur automatischen Druckerabschaltung (Auto Power Off)",
    "Impostazione spegnimento automatico",
    "Auto Power Off Instelling"
};

const char MMSG_POWEROFF_VALUE1[8][15] PROGMEM = {
	"   关闭",
	"  Disable",
 	"  閉じる",
	" Inhabilitar",
    " Désactiver",
    " Deaktiviert",
    " disattivare",
    "Uitgeschakeld"
};

const char MMSG_POWEROFF_VALUE2[8][12] PROGMEM = {
	"  1分钟",
	"  1 min",
 	"  1分",
	" 1 minuto",
    " 1 minute",
    "  1 Min.",
    " 1 minuto",
    "  1 min"
};

const char MMSG_POWEROFF_VALUE3[8][12] PROGMEM = {
	"  5分钟",
	"  5 min",
 	"  5分",
	"5 minutos",
    "5 minutes",
    "  5 Min.",
    "5 minuti",
    "  5 min"
};

const char MMSG_POWEROFF_VALUE4[8][12] PROGMEM = {
	"  10分钟",
	"  10 min",
 	"  10分",
	"10 minutos",
    "10 minutes",
    "  10 Min.",
    "10 minuti",
    "  10 min"
};

const char MMSG_POWEROFF_VALUE5[8][12] PROGMEM = {
	"  15分钟",
	"  15 min",
 	"  15分",
	"15 minutos",
    "15 minutes",
    "  15 Min.",
    "15 minuti",
    "  15 min"
};

const char MMSG_POWEROFF_VALUE6[8][12] PROGMEM = {
	"  30分钟",
	"  30 min",
 	"  30分",
	"30 minutos",
    "30 minutes",
    "  30 Min.",
    "30 minuti",
    "  30 min"
};

const char MMSG_SELF_TEST_TITLE[8][25] PROGMEM = {
	"开机自检",
	"Post",
 	"セルフテスト",
	"Autoprueba de encendido",
    "Publier",
    "Druckerselbstest (POST)",
    "Inviare",
    "Zelftest"
};

const char MMSG_SKIP[8][16] PROGMEM = {
	"  跳过",
	"  Skip",
 	" スキップ",
	"  Saltar",
    "  Sauter",
    "Uberspringen",
    "  Salta",
    " Overslaan"
};

const char MMSG_SELF_TEST_ITEM1[8][35] PROGMEM = {
	"左喷头加热:",
	"Left Nozzle Heating:",
 	"左ノズル加熱:",
	"Boquilla izquierda:",
	"Buse gauche Chauffage:",
	"Aufheizen der linken Düse:",
	"CloLeft ugello di riscaldamento:",
    "Linker Printkop Opwarmen:"
};

const char MMSG_SELF_TEST_ITEM2[8][35] PROGMEM = {
	"右喷头加热:",
	"Right Nozzle Heating:",
 	"右ノズル加熱:",
	"Boquilla derecha:",
	"Buse droite chauffage:",
	"Aufheizen der rechten Düse:",
	"Riscaldamento dell'ugello destro:",
    "Rechter Printkop Opwarmen:"
};

const char MMSG_SELF_TEST_ITEM3[8][32] PROGMEM = {
	"平台加热:",
	"Bed Heating:",
 	"ベッド暖房:",
	"Plataforma",
    "Chauffage du lit:",
    "Aufheizen des Druckbettes:",
    "Letto riscaldamento:",
    "Bed Opwarmen:"
};

const char MMSG_SELF_TEST_ITEM4[8][26] PROGMEM = {
	"X轴归位:",
	"X Axis Homing:",
 	"X軸ホーミング:",
	"X Axis Homing:",
    "X Homing:",
    "Grundstellung X-Axe:",
    "X Homing:",
    "X As Homing"
};

const char MMSG_SELF_TEST_ITEM5[8][26] PROGMEM = {
	"Y轴归位:",
	"Y Axis Homing:",
 	"Y軸ホーミング:",
	"Y Axis Homing:",
    "Et Homing:",
    "Grundstellung Y-Axe:",
    "E Homing:",
    "Y As Homing"
};

const char MMSG_SELF_TEST_ITEM6[8][26] PROGMEM = {
	"Z轴归位:",
	"Z Axis Homing:",
 	"Z軸ホーミング:",
	"Z Axis Homing:",
    "Z Homing:",
    "Grundstellung Z-Axe:",
    "Z Homing:",
    "Z As Homing"
};

const char MMSG_SELF_TEST_PASS[8][11] PROGMEM = {
	"正常",
	"PASS",
 	"合格",
	"PASAR",
    "PASSER",
    "PASS",
    "PASSAGGIO",
    "Geslaagd"
};

const char MMSG_SELF_TEST_NOTEMP[8][41] PROGMEM = {
	"无法读取温度!",
	"Temperature can't be read!",
 	"温度を読み取れません!",
	"Error de temperatura",
    "La température ne peut pas être lue!",
    "Temperatur kann nicht ermittelt werden!",
    "La temperatura non può essere letta!",
    "Temperatuur kan niet worden afgelezen!"
};

const char MMSG_SELF_TEST_NOHEAT[8][26] PROGMEM = {
	"加热失败!",
	"Heating fail!",
 	"加熱失敗!",
	"Falla de calentamiento",
    "Echec du chauffage!",
    "Aufheizen fehlerhaft!",
    "Riscaldamento fallito!",
    "Opwarm fout!"
};

const char MMSG_SELF_TEST_HEATING[8][15] PROGMEM = {
	"正在加热...",
	"Heating...",
 	"加熱...",
	"Calefacción",
    "Chauffage...",
    "Aufheizen...",
    "Riscaldamento",
    "Opwarmen..."
};

const char MMSG_SELF_TEST_RUNOUT_OK[8][17] PROGMEM = {
	"料丝已插入",
	"Filament OK",
 	"フィラメント挿入",
	"Filamento ok",
    "Filament OK",
    "Filament OK",
    "Filamento OK",
    "Filament OK"
};

const char MMSG_SELF_TEST_RUNOUT_FAIL[8][23] PROGMEM = {
	"未检测到料丝",
	"NO Filament",
 	"ワイヤーが検出されない",
	"NO filamento",
    "PAS de filament",
    "Filament fehlt",
    "NESSUN filamento",
    "Geen Filament"
};

const char MMSG_SELF_TEST_MOVING[8][25] PROGMEM = {
	"正在移动...",
	"Moving...",
 	"移動しています...",
	"Emocionante",
    "En mouvement...",
    "bewege Achsen...",
    "In movimento...",
    "Aan het verplaatsen..."
};

const char MMSG_SELF_TEST_NOHOMING[8][16] PROGMEM = {
	"无法归位!",
	"Homing Fail!",
 	"ホーミング失敗!",
	"Homing fallo!",
    "Homing Fail!",
    "Homing Fail!",
    "Homing Fail!",
    "Homing Fout!"
};

const char MMSG_HELP_TITLE[8][11] PROGMEM = {
	"帮助",
	"Help",
 	"助けて",
	"Ayuda",
    "Aidez-moi",
    "Hilfe",
    "Aiuto",
    "Help"
};

const char MMSG_HELP_GUIDE[8][18] PROGMEM = {
	"    使用向导",
	"   Quick Guide",
 	"  クイックガイド",
	"   Guía rápida",
    "  Guide rapide",
    " Kurzanleitung",
    "  Guida veloce",
    "  Snelgids"
};

const char MMSG_HELP_FAQ[8][20] PROGMEM = {
	"    常见问题",
	"      FAQ",
 	"   よくある質問",
	"      FAQ",
    "      FAQ",
    "      FAQ",
    "      FAQ",
    "      FAQ"
};

const char MMSG_HELP_DIAG[8][22] PROGMEM = {
	"    故障诊断",
	"  Error Diagnosis",
 	"  エラーしんだん",
	"   Diagnostico",
    "   Diagnostic",
    "  Fehlerdiagnose",
    "    Diagnosi",
    "  Fout Diagnose"
};

const char MMSG_HELP_WIKI[8][22] PROGMEM = {
	"    在线Wiki",
	"     Wiki",
 	"     Wiki",
	"     Wiki",
    "     Wiki",
    "     Wiki",
    "     Wiki",
    "     Wiki"
};

const char MMSG_HELP_CONTACT[8][22] PROGMEM = {
	"    联系我们",
	"   Contact Us",
 	"  お問い合わせ",
	"    Contacto",
    " Nous contacter",
    "   Kontakt",
    "   Contattaci",
    " Contacteer Ons"
};

const char MMSG_SAVE_PRINTING[8][54] PROGMEM = {
	"正在保存打印进度...",
	"Saving print progress...",
 	"印刷の進行状況を保存しています...",
	"Guardando progreso de impresión ...",
    "Enregistrement de la progression de l'impression...",
    "Speichere aktuellen Druckstatus...",
    "Salvataggio avanzamento stampa...",
    "Printvoortgang opslaan..."
};

const char MMSG_RESUME_LINE[8][148] PROGMEM = {
	"\r\n发现保存进度, 是否恢复打印?",
	"\r\nFound the save progress,\r\nresume printing?",
 	"\r\n保存の進行状況がわかりました,\r\n印刷を再開しますか?",
	"\r\nEncontró el progreso de guardar,\r\nreanudar la impresión?",
    "\r\nTrouvé la progression de la sauvegarde,\r\nreprendre l'impression?",
    "\r\nDer letzte Druck wurde unterbrochen und der aktuelle Status gespeichert.\r\nWollen Sie den Druck an der gespeicherten Position fortsetzen?",
    "\r\nTrovato l'avanzamento del salvataggio,\r\nriprendere la stampa?",
    "\r\nPrintvoortgang gevonden, verder met printen?"
};

const char MMSG_RESUME_PRINTING[8][46] PROGMEM = {
	"正在恢复打印进度...",
	"Resuming print progress...",
 	"印刷の進行状況を再開しています...",
	"Reanudando el progreso de impresión",
    "Reprise de la progression de l'impression...",
    "Setze Druck an gespeicherter Position fort...",
    "Ripresa dell'avanzamento della stampa...",
    "Print Hervatten..."
};

const char MMSG_HELPLIST_TITLE[8][13] PROGMEM = {
	"常见问题",
	"FAQ",
 	"よくある質問",
	"FAQ",
    "FAQ",
    "FAQ",
    "FAQ",
    "FAQ"
};

const char MMSG_PRINTING_NOTICE[8][116] PROGMEM = { 
	"\r\n\r\n 请暂停后再进行操作",
	"\r\n\r\n Please pause before proceeding",
    "\r\n\r\n 続行する前に一時停止してください",
	"\r\n\r\n Pausa antes de continuar",
    "\r\n\r\n Veuillez faire une pause avant de continuer",
    "\r\n Diese Funktion ist wahrend eines Druckes nicht moglich. Sie müssen den Druck erst pausieren oder beenden!",
    "\r\n\r\n Metti in pausa prima di procedere",
    "\r\n\r\nGraag pauseren alvorens verder te gaan"
};

const char MMSG_LEVEL_HIGHT_TITLE[8][40] PROGMEM = {
	"选择Z轴高度 ",
	"Select the Z axis height",
	"フィラメントの種類",
	"Seleccione la altura del eje Z",
    "Sélectionnez la hauteur de l'axe Z",
    "Select the Z axis height",
    "Seleziona l'altezza dell'asse Z.",
    "Selecteer de Z as hoogte"
};

const char MMSG_FIRMWARE_PARAM_TITLE[8][30] PROGMEM = {
	"固件参数",
	"Firmware Parameters",
	"ファームウェアパラメーター",
	"Parámetros del firmware",
    "Paramètres du micrologiciel",
    "Firmware Parameter",
    "Parametri firmware",
    "Firmware Instellingen"
};

const char MMSG_FIRMWARE_PARAM_OPERATION[8][25] PROGMEM = {
	"保存或恢复",
	"Save&Load",
	"保存または復元",
	"Guardar o restaurar",
    "Sauvegarder charger",
    "Datei Speichern&Laden",
    "Salva e carica",
    "Opslaan&Openen"
};

const char MMSG_FIRMWARE_PARAM_SAVE[8][23] PROGMEM = {
	"  保存至TF卡",
	"  Save to TF",
	" TFカードに保存",
	"  Guardar en TF",
    "Enregistrer sur TF",
    "Auf MicroSD speichern",
    "  Salva in TF",
    " Opslaan naar TF"
};

const char MMSG_FIRMWARE_PARAM_LOAD[8][20] PROGMEM = {
	"  从TF卡恢复",
	"  Load from TF",
	" TFカードから回復",
	" Cargar desde TF",
    "Charger depuis TF",
    "Von MicroSD laden",
    "  Carica da TF",
    " Openen vanaf TF"
};

const char MMSG_FIRMWARE_PARAM_RESTORE[8][20] PROGMEM = {
	"  恢复出厂设置",
	"  Load Default",
	"   工場リセット",
	"  Recuperación",
    "Charge par défaut",
    " Standard laden",
    "Carica predefinito",
    " Laad standaard"
};

const char MMSG_PREVIEW_TITLE[8][30] PROGMEM = {
	"文件信息",
	"File Information",
 	"ファイル情報",
	"Informacion del archivo",
    "Informations sur le fichier",
    "Dateiinformationen",
    "Informazioni sui file",
    "Bestand Informatie"
};

const char MMSG_PREVIEW_PRINT[8][13] PROGMEM = {
	"  打印",		
	"  Print",
	"  印刷する",
	" Impresión",
    " Impression",
    "   Druck",
    "  Stampa",
    "  Print"
};


const char MMSG_FILAMENT_CHOICE_EXTRUDER_TITLE[8][24] PROGMEM = {
	"选择喷头",
	"Select Nozzle",
    "ノズルを選択",
	"Seleccionar boquilla",
    "Sélectionnez la buse",
    "Wahle Düse",
    "Seleziona Ugello",
    "Selecteer Printkop"
};

const char MMSG_FILAMENT_LEFT_EXTRUDER[8][30] PROGMEM = {
	"    左喷头",
	"  Left Nozzle",
    "    左ノズル",
	" Boquilla izquierda",
    "  Buse gauche",
    "  Linke Düse",
    "  Ugello sinistro",
    " Linker Printkop"
};

const char MMSG_FILAMENT_RIGHT_EXTRUDER[8][30] PROGMEM = {
	"    右喷头",
	"  Right Nozzle",
    "    右ノズル",
	" Boquilla derecha",
    "  Buse droite",
    "  Rechte Düse",
    "  Ugello destro",
    " Rechter Printkop"
};

const char MMSG_STOPPED[] PROGMEM = { "STOPPED. " };
const char MMSG_ERR_Z_HOMING[] PROGMEM = { "Home XY first" };
const char MMSG_ZPROBE_OUT[] PROGMEM = { "Z Probe past bed" };

const char MMSG_CONFIG_OPEN_FAIL[8][70]PROGMEM = {
	"无法打开参数保存文件.",		
	"Open config save file fail.",
	"構成保存ファイルを開くことができません.",
	"El archivo de configuración de guardado abierto falla.",
    "Echec de l'ouverture du fichier de sauvegarde de la configuration.",
    "Konnte Konfigurationsdatei nicht laden.",
    "Apertura del file di salvataggio della configurazione non riuscita.",
    "Fout met openen configuratie bestand."
};

const char MMSG_CONFIG_WRITE_FAIL[8][72]PROGMEM = {
	"无法写入参数保存文件.",		
	"Write to config save file fail.",
	"構成保存ファイルへの書き込みに失敗しました.",
	"Escribir en el archivo de configuración de guardar falla.",
    "Echec de l'écriture dans le fichier de sauvegarde de la configuration.",
    "Konnte Konfigurationsdatei nicht speichern.",
    "Scrittura nel file di salvataggio della configurazione non riuscita.",
    "Fout met bewaren configuratie bestand."
};

const char MMSG_CONFIG_SAVE_OK[8][40]PROGMEM = {
	"保存参数成功.",		
	"Parameters saved successfully.",
	"パラメータが正常に保存されました.",
	"Parámetros guardados con éxito.",
    "Paramètres enregistrés avec succès.",
    "Parameter erfolgreich gespeichert.",
    "Parametri salvati con successo.",
    "Instellingen succesvol opgeslagen."
};

const char MMSG_CONFIG_LOAD_OK[8][54]PROGMEM = {
	"恢复参数成功.",		
	"Parameter recovery succeeded.",
	"パラメータの復元に成功しました。",
	"La recuperación de parámetros tuvo éxito.",
    "La récupération des paramètres a réussi.",
    "Parameter erfolgreich geladen.",
    "Il ripristino dei parametri è riuscito.",
    "Instellingen herstel geslaagd."
};

const char MMSG_STORE_TITLE[8][19]PROGMEM = {
	"存储器",		
	"Disk",
	"ディスク",
	"Disco",
    "Disque",
    "Speichermedium",
    "Disco",
    "Schijf"
};

const char MMSG_STORE_TF[8][16]PROGMEM = {
	"     TF卡",		
	"    TF Card",
	"    TFカード",
	"   Tarjeta TF",
    "    Carte TF",
    "    MicroSD",
    "  Carta di TF",
    "   TF kaart"
};

const char MMSG_STORE_WIFIDISK[8][18]PROGMEM = {
	"     WIFI盘",		
	"    WIFI Disk",
	"   WIFIディスク",
	"   Disco WIFI",
    "   Disque WIFI",
    "    WIFI Disk",
    "   Disco WIFI",
    "   WiFi kaart"
};

const char MMSG_LOADING[8][44] PROGMEM = {
	"\r\n\r\n 正在载入, 请稍等...",
	"\r\n\r\n Loading, please wait...",
 	"\r\n\r\n 読み込み中...待って下さい...",
	"\r\n\r\n Cargando por favor espere...",
    "\r\n\r\n Chargement, veuillez patienter...",
    "\r\n\r\n Lade, bitte warten...",
    "\r\n\r\n Attendere il caricamento prego...",
    "\r\n\r\nLaden, even moment geduld..."
};

const char MMSG_IAP_TITLE[8][28] PROGMEM = {
	"升级固件",
	"Update",
	"更新する",
	"Actualización",
    "Mettre à jour",
    "Aktualisierung (Update)",
    "Aggiornare",
    "Update"
};

const char MMSG_IAP_TIP[8][156] PROGMEM = {
	"社区版固件不支持在线更新",
	"Community firmware not support IAP",
	"ファームウェア更新ファイルflash.wfmをTFカードのルートディレクトリにコピーしてください.\r\n[ベギン]をクリックして更新します.",
	"Copie el archivo de actualización de firmware flash.wfm en el directorio raíz de la tarjeta TF.\r\nHaga clic en Comenzar para actualizar.",
    "Veuillez copier le fichier de mise à jour du micrologiciel flash.wfm dans le répertoire racine de la carte TF.\r\nCliquez sur Commencer à mettre à jour.",
    "Bitte kopieren Sie  die Firmwaredatei flash.wfm in das Stammverzeichnis der MicroSD-Karte.\r\nUm das Update zu beginnen klicken Sie auf Start",
    "Copiare il file di aggiornamento del firmware flash.wfm nella directory principale della scheda TF.\r\nFare clic su Inizia ad aggiornare.",
    "Kopieer het firmware update bestand flash.wfm naar de root directory van de TF kaart. \r\nKlik op Start om de update uit te voeren."
};

const char MMSG_IAP_CHECK_FILE[8][33] PROGMEM = {
	"正在检查文件...",
	"Checking file...",
	"ファイルをチェックしています...",
	"Comprobando archivo ...",
    "Vérification du fichier...",
    "Prüfe Datei...",
    "Controllo file in corso...",
    "Bestand controlleren..."
};

const char MMSG_IAP_FILE_FOUND[8][27] PROGMEM = {
	"已找到flash.wfm",
	"flash.wfm found",
	"flash.wfmが見つかりました",
	"flash.wfm encontrado",
    "flash.wfm trouvé",
    "flash.wfm gefunden",
    "flash.wfm trovato",
    "flash.wmf gevonden"
};

const char MMSG_IAP_FILE_NOTFOUND[8][35] PROGMEM = {
	"错误: 未找到flash.wfm",
	"Error: flash.wfm not found",
	"エラー：flash.wfmが見つかりません",
	"Error: flash.wfm no encontrado",
    "Erreur: flash.wfm introuvable",
    "Fehler: flash.wfm nicht gefunden",
    "Errore: flash.wfm non trovato",
    "Fout: flash.wfm niet gevonden"
};

const char MMSG_IAP_CHECK_VERSION[8][33] PROGMEM = {
	"正在检查版本...",
	"Checking version...",
	"バージョンを確認しています...",
	"Comprobando versión...",
    "Vérification de la version...",
    "Prüfe Version...",
    "Verifica versione...",
    "Versie controle..."
};

const char MMSG_IAP_FILE_NOTOPEN[8][45] PROGMEM = {
	"无法打开flash.wfm",
	"Error: cannot read flash.wfm",
	"エラー：flash.wfmを読み取れません",
	"Error: no se puede leer flash.wfm",
    "Erreur: impossible de lire flash.wfm",
    "Fehler: flash.wfm kann nicht gelesen werden",
    "Errore: impossibile leggere flash.wfm",
    "Fout: kan flash.wfm niet lezen"
};

const char MMSG_IAP_FILE_NOINFO[8][60] PROGMEM = {
	"无法读取版本信息",
	"Error: unable to read version info",
	"エラー：バージョン情報を読み取れません",
	"Error: no se puede leer la información de la versión",
    "Erreur: impossible de lire les informations de version",
    "Fehler: Die Versionsinformation kann nicht gelesen werden",
    "Errore: impossibile leggere le informazioni sulla versione",
    "Fout: kan versie info niet lezen"
};

const char MMSG_IAP_FILE_INFO[8][38] PROGMEM = {
	"升级文件版本:",
	"Update file version:",
	"ファイルバージョンの更新：",
	"Actualizar la versión del archivo:",
    "Mettre à jour la version du fichier:",
    "Update Version:",
    "Aggiorna la versione del file:",
    "Update bestand versie:"
};

const char MMSG_IAP_DEVICE_INFO[8][20] PROGMEM = {
	"当前版本:",
	"Current version:",
	"現行版：",
	"Versión actual:",
    "Version actuelle:",
    "Aktuelle Version:",
    "Versione attuale:",
    "Huidige versie:"
};

const char MMSG_IAP_BEGIN[8][48] PROGMEM = {
	"等待开始更新...",
	"Waiting for the update to begin...",
	"更新が始まるのを待っています...",
	"Esperando a que comience la actualización...",
    "En attente du début de la mise à jour...",
    "Warte auf Start des Updates...",
    "In attesa dell'inizio dell'aggiornamento...",
    "Wacht op starten update..."
};

const char MMSG_IAP_NONEED[8][38] PROGMEM = {
	"社区版固件不支持在线更新",
	"Community firmware not support IAP",
	"更新する必要はありません",
	"No es necesario actualizar",
    "Pas besoin de mettre à jour",
    "Nichts zu aktualisieren",
    "Non c'è bisogno di aggiornare",
    "Update niet nodig"
};

const char MMSG_IAP_FILE_DEVICE[8][45] PROGMEM = {
	"升级文件机型:",
	"Update file device:",
	"ファイルデバイスの更新：",
	"Actualizar dispositivo de archivo:",
    "Mettre à jour le périphérique de fichier:",
    "Gerat lt. Update:",
    "Aggiorna dispositivo file:",
    "Update bestand apparaat:"
};

const char MMSG_IAP_CURRENT_DEVICE[8][24] PROGMEM = {
	"当前设备:",
	"Current device:",
	"現在のデバイス：",
	"Dispositivo actual:",
    "Appareil actuel:",
    "Aktuelles Gerat:",
    "Dispositivo corrente:",
    "Huidig apparaat:"
};

const char MMSG_IAP_DEVICE_NOMATCH[8][40] PROGMEM = {
	"错误: 机型不匹配",
	"Error: Device not match",
	"エラー：デバイスが一致しません",
	"Error: el dispositivo no coincide",
    "Erreur: l'appareil ne correspond pas",
    "Fehler: Gerate stimmen nicht überein",
    "Errore: dispositivo non corrispondente",
    "Fout: Apparaat komt niet overeen"
};

const char MMSG_IAP_SIZE_ERROR[8][42] PROGMEM = {
	"文件大小错误",
	"Error: Wrong file size",
	"エラー：ファイルサイズが間違っています",
	"Error: tamaeo de archivo incorrecto",
    "Erreur: taille de fichier incorrecte",
    "Fehler: Dateigrobe fehlerhaft",
    "Errore: dimensione del file errata",
    "Fout: Verkeerde bestandsgrootte"
};

const char MMSG_WIKI_TITLE[8][22] PROGMEM = {
	"Wiki网站",
	"Wiki site",
 	"Wikiサイト",
	"Sitio Wiki",
    "Site Wiki",
    "Wiki-Site",
    "Sito Wiki",
    "Wiki site"
};

const char MMSG_WIKI_URL[] PROGMEM = {
    "www.weedo3dprinter.com"
};

const char MMSG_CONTACT_TITLE[8][22] PROGMEM = {
	"联系我们",
	"Contact Us",
 	"お問い合わせ",
	"Contáctenos",
    "Nous contacter",
    "Kontakt",
    "Contattaci",
    "Contacteer Ons"
};

const char MMSG_CONTACT_TEXT[8][160] PROGMEM = {
    "产品官网: www.weedo.ltd\r\nWiki网站: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\n售后邮箱: support@wiibooxtech.com",
    "website: www.weedo.ltd\r\nwikisite: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\nemail: support@wiibooxtech.com",
    "ウェブサイト: www.weedo.ltd\r\nwikiサイト: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\nEメール: support@wiibooxtech.com",
    "sitio web: www.weedo.ltd\r\nsitio wiki: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\ncorreo electrónico: support@wiibooxtech.com",
    "site Web: www.weedo.ltd\r\nwikisite: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\ncourriel: support@wiibooxtech.com",
    "Website: www.weedo.ltd\r\nwikisite: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\nE-Mail: support@wiibooxtech.com",
    "sito web: www.weedo.ltd\r\nwikisite: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\ne-mail: support@wiibooxtech.com",
    "website: www.weedo.ltd\r\nwikisite: www.weedo3dprinter.com\r\nfacebook: www.facebook.com/Weedo3d\r\nemail: support@wiibooxtech.com\r\n"
};


const char MMSG_PREVIEW_MODE[8][20] PROGMEM = {
	"双喷头模式",
	"Dual Mode",
 	"デュアルモード",
	"Modo dual",
    "Mode double",
    "Druckmodus",
    "Modalità doppia",
    "Dual Modus"
};

const char MMSG_DUAL_NORMAL[8][20] PROGMEM = {
	"    普通模式",
	"    Normal",
 	"  ノーマルモード",
	"    Normal",
    "   Ordinaire",
    "    Normal",
    "    Normale",
    "    Normaal"
};

const char MMSG_DUAL_COPY[8][20] PROGMEM = {
	"    复制模式",
	"    Duplication",
 	"   コピーモード",
	"    Duplicación",
    "   Reproduction",
    "    Duplizieren",
    "   Duplicazione",
    "    Dupliceren"
};

const char MMSG_DUAL_MIRROR[8][20] PROGMEM = {
	"    镜像模式",
	"    Mirrored",
 	"   ミラーモード",
	"    Reflejado",
    "    Miroir",
    "    Spiegeln",
    "   Rispecchiato",
    "    Spiegelen"
};

const char MMSG_LEVEL_DATA_TITLE[8][36] PROGMEM = {
	"平面度测试结果",
	"Flatness Test Result",
 	"平面度テスト結果",
	"Resultado de la prueba de planitud",
    "Résultat du test de planéité",
    "Ergebnis des Bettleveltests",
    "Risultato del test di planarità",
    "Vlakheid Test Resultaat"
};

const char MMSG_LEVEL_DATA_TEXT[8][138] PROGMEM = {
	"测试数据仅供参考\r\n自动调平功能可以自动补偿平面度误差",
	"Test data is for reference only.\r\nThe auto bed leveling can compensate for flatness errors.",
 	"テストデータは参考用です\r\n自動レベリング機能は、平坦度エラーを自動的に補正できます",
	"La nivelación automática de la cama puede compensar los errores de planitud.",
    "Les données de test sont à titre indicatif uniquement.\r\nLa mise à niveau automatique du lit peut compenser les erreurs de planéité.",
    "Die Testdaten dienen nur zur Orientierung.\r\nDas automatische Bettleveling kann vorhandene Fehler ausgleichen.",
    "I dati del test sono solo di riferimento.\r\nIl livellamento automatico del letto può compensare gli errori di planarità.",
    "Test resultaat dient enkel als referentie.\r\nDe auto bed leveling compenseert de gevonden afwijkingen."
};

const char MMSG_FITNESS_ERROR_TITLE[8][38] PROGMEM = {
	"平面度错误警告",
	"Flatness Error Warning",
 	"平面度エラー警告",
	"Advertencia de error de planitud",
    "Avertissement d'erreur de planéité",
    "Druckbettlevelwarnung",
    "Avviso di errore di planarità",
    "Vlakheid Fout Waarschuwing"
};

const char MMSG_FITNESS_ERROR_TEXT[8][126] PROGMEM = {
	"平面度误差过大,继续打印会损坏设备\r\n建议取消打印.",
	"The flatness error, continuing to print will damage the printer. It is recommended to cancel the printing.",
 	"平面度エラーが大きすぎるため,印刷を続行するとデバイスが損傷します. 印刷をキャンセルすることをお勧めします.",
	"El error de planitud, continuar imprimiendo daeará la impresora. Se recomienda cancelar la impresión.",
    "L'erreur de planéité, la poursuite de l'impression endommagera l'imprimante. Il est recommandé d'annuler l'impression.",
    "Das Druckbett ist uneben, wenn Sie weiterdrucken kann der Drucker Schaden nehmen. Es wird empfohlen den Druck abzubrechen!",
    "L'errore di planarità, continuando a stampare, danneggerà la stampante. Si consiglia di annullare la stampa.",
    "Vlakheid fout, het wordt aangeraden het printen te stoppen. Verdergaan kan de printer beschadigen."
};


const char MMSG_NOZZLE_OFFSET[8][20] PROGMEM = {
	"   双喷头偏置",
	"  Nozzle Offset",
 	" ノズルオフセット",
	"   Compensar",
    "   buse Offset",
    "  Düsenversatz",
    "  Offset ugello",
    "Printkop Afstand"
};

const char MMSG_NOZZLE_OFFSET_TITLE[8][38] PROGMEM = {
	"双喷头偏置调节",
 	"Nozzle Offset Adjustment",
    "ダブルノズルオフセット調整",
	"Desplazamiento de la boquilla",
    "Réglage du décalage de la buse",
    "Düsenversatzjustierung (Offset)",
    "Regolazione dell'offset degli ugelli",
    "Printkop Afstand Aanpassing"
};

const char MMSG_NOZZLE_X_OFFSET[8][20] PROGMEM = {
	"  XY偏置粗调",
 	" XY Coarse Tune",
	"XYオフセット粗調整",
	"XY Melodía Gruesa",
    "XY gros morceau",
    "XY Grobabstimmung",
    "XY Coarse Tune",
    "XY Grove Afstelling"
};

const char MMSG_NOZZLE_XY_OFFSET[8][20] PROGMEM = {
	"  XY偏置精调",
 	"  XY Fine Tune",
	"XYオフセット微調整",
	" Ajuste fino XY",
    " Réglage fin XY",
    "XY Feineinstellung",
    "  XY Fine Tune",
    "XY Fijne Afstelling"
};

const char MMSG_NOZZLE_Z_OFFSET[8][20] PROGMEM = {
	"   Z偏置调节",
 	" Z Offset Tune",
	" Zオフセット調整",
	" Z Offset Tune",
    " Z Offset Tune",
    " Z Einstellung",
    " Z Offset Tune",
    "Z Marge Afstelling"
};

const char MMSG_NOZZLE_X_TITLE[8][55] PROGMEM = {
	"喷头XY偏置粗调",
 	"Nozzle XY Offset Coarse Tune",
	"ノズルXYオフセット粗調整",
	"Boquilla XY Offset Coarse Tune",
    "Réglage grossier décalé de la buse XY",
    "Düsen XY-Versatz (Offset) Grobeinstellung",
    "Regolazione approssimativa dell'offset dell'ugello XY.",
    "Printkop XY Afstand"
};

const char MMSG_NOZZLE_X_TEXT[8][190] PROGMEM = {
	"打印文件NozzleCoarseTune.gcode\r\n选择水平方向两层偏差最小的测试块上的数字, 点击下一步.",
	"Print the file NozzleCoarseTune.gcode\r\nSelect the number on the block with the smallest horizontal deviation, and click Next.",
 	"ファイルNozzleCoarseTune.gcodeファイルを印刷します\r\n2つのレイヤーの水平方向の偏差が最も小さいテストブロックの番号を選択し,[次へ]をクリックします.",
	"Imprima el archivo Nozzle CourseTune.gcode. Seleccione el número en el bloque con la desviación horizontal más pequena y haga clic en Siguiente.",
    "Imprimez le fichier NozzleCoarseTune.gcode\r\nSélectionnez le numéro sur le bloc avec le plus petit écart horizontal et cliquez sur Suivant.",
    "Drucken Sie die Datei NozzleCoarseTune.gcode\r\nWahlen Sie anschliebend die Nummer des Blocks mit der geringsten horizontalen Abweichung und klicken Sie auf Fortfahren.",
    "Stampa il file NozzleCoarseTune.gcode\r\nSelezionare il numero sul blocco con la deviazione orizzontale più piccola e fare clic su Avanti.",
    "Print het bestand NozzleCoarseTune.gcode.\r\nSelecteer het nummer van het blokje met de kleinste horizontale afwijking en klik op Volgende."
};

const char MMSG_NOZZLE_XY_TITLE[8][46] PROGMEM = {
	"喷头XY偏置精调",
 	"Nozzle XY Offset Fine Tune",
	"印字ヘッドXYオフセット微調整",
	"Boquilla XY Offset Fine Tune",
    "Réglage précis du décalage XY de la buse",
    "Düsen XY-Versatz (Offset) Feineinstellung",
    "Regolazione fine offset XY ugello",
    "Printkop XY Afstand Fijne Afstelling"
};

const char MMSG_NOZZLE_Y1_TEXT[8][180] PROGMEM = {
	"打印文件NozzleFintTune.gcode\r\n选择水平方向两层偏差最小的测试块上的数字, 点击下一步.",
	"Print the file NozzleFintTune.gcode. Select the number on the block with the smallest horizontal deviation, and click Next.",
 	"NozzleFintTune.gcodeファイルを印刷します\r\n2つのレイヤーの水平方向の偏差が最も小さいテストブロックの番号を選択し,[次へ]をクリックします.",
	"Imprima el archivo NozzleFintTune.gcode. Seleccione el número en el bloque con la desviación horizontal más pequena y haga clic en Siguiente.",
    "Imprimez le fichier NozzleFintTune.gcode. Sélectionnez le numéro sur le bloc avec le plus petit écart horizontal et cliquez sur Suivant.",
    "Drucken Sie die Datei NozzleFintTune.gcode. Wahlen Sie anschliebend die Nummer des Blocks mit der geringsten horizontalen Abweichung und klicken Sie auf Fortfahren.",
    "Stampa il file NozzleFintTune.gcode. Selezionare il numero sul blocco con la deviazione orizzontale più piccola e fare clic su Avanti.",
    "Print het bestand NozzleFineTune.gcode. Selecteer het nummer van het blokje met de kleinste horizontale afwijking en klik op Volgende."
};

const char MMSG_NOZZLE_Y2_TEXT[8][150] PROGMEM = {
	"选择垂直方向两层偏差最小的测试块上的数字, 点击保存完成设置.",
	"Select the number on the block with the smallest deviation between the two vertical layers, and Save.",
 	"2つの垂直レイヤー間の偏差が最も小さいテストブロックの番号を選択し, [保存]をクリックして設定を完了します.",
	"Seleccione el número en el bloque con la desviación más pequena entre las dos capas verticales y Guardar.",
    "Sélectionnez le numéro sur le bloc présentant le plus petit écart entre les deux couches verticales et enregistrez.",
    "Wahlen Sie die Nummer des Blocks mit der geringsten Abweichung zwischen den beiden vertikalen Schichten und klicken Sie auf Speichern.",
    "Seleziona il numero sul blocco con la deviazione più piccola tra i due strati verticali e Salva.",
    "Selecteer het nummer van het blokje met de kleinste afwijking tussen de twee vertikale lagen en kies Opslaan."
};

const char MMSG_NOZZLE_Z_TITLE[8][40] PROGMEM = {
	"喷头Z偏置调节",
 	"Nozzle Z Offset Tune",
	"ノズルZオフセット調整",
	"Boquilla Z Offset Tune",
    "Réglage du décalage de la buse Z",
    "Düsen Z-Versatz (Offset) Einstellung",
    "Regolazione offset Z ugello",
    "Printkop Z Afstand Afstelling"
};

const char MMSG_NOZZLE_Z_TEXT1[8][320] PROGMEM = {
	"在开始校准前, 请先在左右喷头中载入料丝, 并清除喷头下挤出的多余料丝. 待喷头冷却后松开两喷头右侧固定机米, 将喷头向上推至最顶端后锁紧机米. 然后准备一张白纸放于平台之上.\r\n准备好后点击开始.",
	"Before calibration, please load the filaments in the double nozzles, and then clean the nozzles. After the nozzle has cooled down, loosen thefixed meter on the right side of  the nozzles, push the nozzles up tothe top and lock the meter. Prepare a paper on the bed.",
	"キャリブレーションの前に, フィラメントをダブルノズルにロードしてから, ノズルを清掃してください. ノズルが冷えたら, ノズル右側の固定メーターを緩め, ノズルを上に押し上げてメーターをロックします. ベッドの上に紙を用意します. すべての準備ができたら, [開始]をクリックします.",
	"Antes de la calibración, cargue los filamentos en las boquillas dobles y luego limpie las boquillas. Después de que la boquilla se haya enfriado, afloje el medidor fijo en el lado derecho de las boquillas, empuje las boquillas hacia arriba y bloquee el medidor. Prepara un papel sobre la cama.",
	"Avant l'étalonnage, veuillez charger les filaments dans les buses doubles, puis nettoyer les buses. Une fois la buse refroidie, desserrez le compteur fixe sur le coté droit des buses, poussez les buses vers le haut et verrouillez le compteur. Préparez un papier sur le lit.",
	"Laden Sie vor der Kalibrierung die Filamente in die Doppeldüsen und reinigen Sie die Düsen. Losen Sie nach dem Abkühlen der Düse das feste Messgerat auf der rechten Seite der Düsen, schieben Sie die Düsen nach oben und verriegeln Sie das Messgerat. Bereiten Sie ein Papier auf dem Bett vor.",
	"Prima della calibrazione, caricare i filamenti nei doppi ugelli, quindi pulire gli ugelli. Dopo che l'ugello si è raffreddato, allentare il misuratore fisso sul lato destro degli ugelli, spingere gli ugelli verso l'alto e bloccare lo strumento. Prepara un foglio sul letto.",
	"Laad vóór de kalibratie de filamenten in de dubbele spuitmonden en reinig vervolgens de spuitmonden. Nadat het mondstuk is afgekoeld, maakt u de vaste meter aan de rechterkant van de mondstukken los, drukt u de spuitmonden naar boven en vergrendelt u de meter. Leg een papier op het bed."
};

const char MMSG_NOZZLE_Z_TEXT2[8][180] PROGMEM = {
	"请微调z轴高度，直至喷头与平台的间隙为一张纸的厚度.\r\n完成后点下一步.",
	"Please fine-tune the height of the z-axis until the gap between the nozzle and the platform is the thickness of apiece of paper.\r\nClick Next to continue.",
    "ノズルとプラットフォーム間のギャップが紙の厚さになるまで, Z軸の高さを微調整してください. \r\n次へをクリックして続けます.",
	"Ajuste la altura del eje z hasta que el espacio entre la boquilla y la plataforma tenga el grosor de una hoja de papel. Haga clic en Siguiente para continuar.",
    "Veuillez ajuster la hauteur de l'axe z jusqu'à ce que l'écart entre la buse et la plate-forme soit l'épaisseur de chaque papier.\r\nCliquer sur Suivant pour continuer.",
    "Bitte justieren Sie die Hohe der Z-Achse bis der Abstand zwischen Druckbett und Düse nahezu der Papierdicke entspricht.\r\nFür den nachsten Schritt klicken Sie auf Fortfahren.",
    "Si prega di regolare l'altezza dell'asse z fino a quando lo spazio tra l'ugello e la piattaforma è lo spessore di un pezzo di carta.\r\nFare clic su Avanti per continuare.",
    "Pas de hoogte van de Z as aan totdat de afstand tussen de spuitmond en het print platform gelijk is aan de dikte van het papier.\r\nKlik op Verder om door te gaan."
};

const char MMSG_NOZZLE_Z_TEXT3[8][290] PROGMEM = {
	"松开右喷头右侧固定机米, 拽动挤出器处料丝, 将喷头推至与纸接触，然后锁紧机米.\r\n完成后点下一步.",
	"Loosen the fixed machine meter on the right side of the right nozzle, drag the filament out of the extruder to push the nozzle to contact with the paper, and then lock the machine meter. Click Next when finished.",
	"右側のノズルの右側にある固定式のマシンメーターを緩め, フィラメントを押出機から引き出してノズルを押して紙に接触させてから, マシンメーターをロックします.  終了したら, [次へ]をクリックします. ",
	"Afloje el medidor fijo de la máquina en el lado derecho de la boquilla derecha, arrastre el filamento fuera de la extrusora para empujar la boquilla para que entre en contacto con el papel y luego bloquee el medidor de la máquina. Haga clic en Siguiente cuando termine.",
	"Desserrez le compteur fixe de la machine sur le coté droit de la buse droite, faites glisser le filament hors de l'extrudeuse pour pousser la buse au contact du papier, puis verrouillez le compteur de la machine. Cliquez sur Suivant lorsque vous avez terminé.",
	"Losen Sie das feste Maschinenmessgerat auf der rechten Seite der rechten Düse, ziehen Sie das Filament aus dem Extruder, um die Düse auf den Kontakt mit dem Papier zu drücken, und verriegeln Sie dann das Maschinenmessgerat. Klicken Sie auf Weiter, wenn Sie fertig sind.",
	"Allentare il misuratore fisso della macchina sul lato destro dell'ugello destro, trascinare il filamento fuori dall'estrusore per spingere l'ugello a contatto con la carta, quindi bloccare il misuratore della macchina. Fare clic su Avanti al termine.",
	"Maak de vaste machinemeter aan de rechterkant van de rechtermondstuk los, sleep het filament uit de extruder om het mondstuk in contact te brengen met het papier, en vergrendel vervolgens de machinemeter. Klik op Volgende als u klaar bent."
};

const char MMSG_NOZZLE_Z_TEXT4[8][290] PROGMEM = {
	"松开左喷头右侧固定机米, 拽动挤出器处料丝, 将喷头推至与纸接触，然后锁紧机米.\r\n完成后点下一步.",
	"Loosen the fixed machine meter on the right side of the left nozzle, drag the filament out of the extruder to push the nozzle to contact with the paper, and then lock the machine meter. Click Next when finished.",
	"左側のノズルの右側にある固定式のマシンメーターを緩め, フィラメントを押出機からドラッグしてノズルを押して紙に接触させてから, マシンメーターをロックします. 終了したら, [次へ]をクリックします.",
	"Afloje el medidor fijo de la máquina en el lado derecho de la boquilla izquierda, arrastre el filamento fuera de la extrusora para empujar la boquilla para que entre en contacto con el papel y luego bloquee el medidor de la máquina. Haga clic en Siguiente cuando termine.",
	"Desserrez le compteur fixe de la machine sur le coté droit de la buse gauche, faites glisser le filament hors de l'extrudeuse pour pousser la buse au contact du papier, puis verrouillez le compteur de la machine. Cliquez sur Suivant lorsque vous avez terminé.",
	"Losen Sie das feste Maschinenmessgerat auf der rechten Seite der linken Düse, ziehen Sie das Filament aus dem Extruder, um die Düse auf den Kontakt mit dem Papier zu drücken, und verriegeln Sie dann das Maschinenmessgerat. Klicken Sie auf Weiter, wenn Sie fertig sind.",
	"Allentare il misuratore fisso della macchina sul lato destro dell'ugello sinistro, trascinare il filamento fuori dall'estrusore per spingere l'ugello a contatto con la carta, quindi bloccare il misuratore della macchina. Fare clic su Avanti al termine.",
	"Maak de vaste machinemeter aan de rechterkant van het linkermondstuk los, sleep het filament uit de extruder om het mondstuk in contact te brengen met het papier en vergrendel vervolgens de machinemeter. Klik op Volgende als u klaar bent."
};

const char MMSG_WIFI_BOOT_ERROR[8][88] PROGMEM = {
	"网络模块意外断开, 打印中止.",
 	"The WIFI module was disconnected unexpectedly, printing was aborted.",
	"WIFIモジュールが予期せず切断され, 印刷が中止されました。",
	"El módulo WIFI se desconectó inesperadamente y se interrumpió la impresión.",
	"The WIFI module was disconnected unexpectedly, printing was aborted.",
	"Das WiFi-Modul wurde unerwartet beendet, der Druck wurde abgebrochen.",
	"The WIFI module was disconnected unexpectedly, printing was aborted.",
    "De verbinding met de WiFi module is onverwacht verbroken, printproces is afgebroken."
};

const char MMSG_BUTTON_QR[8][13] PROGMEM = {
	"  二维码",			// 
	"  QR code",
	"  QRコード",
	" Código QR",
    "  QR Code",
    "  QR-Code",
    "  QR Code",
    "  QR code"
};

const char MMSG_QR_TITLE[8][31] PROGMEM = {
	"设备序列号二维码",			// 
	"Serial number QR code",
	"シリアル番号QRコード",
	"Número de serie código QR",
    "Numéro de série QR code",
    "QR-Code der Seriennummer",
    "Codice QR del numero di serie",
    "Serienummer QR code"
};

const char MMSG_MAINMENU[8][14] PROGMEM = {
	" 主界面",
	"  Main",
 	" メイン",
	"Principal",
	"Principal",
	"Hauptmenü",
	"Principale",
    "Hoofdmenu"
};

const char MMSG_SETTING_BABYSTEP[8][30]  = {
	"    微调Z轴",
	"  Babystep Z",
	"  Zジク ビドウ",
	"  Micropaso Z",
    "  Babystep Z",
    "  Babystep Z",
    "  Babystep Z",
	"  Babystep Z"
};

const char MMSG_BABYSTEP_TITLE[8][30]  = {
	"微调Z轴",
	"Babystep Z",
	"Zジク ビドウ",
	"Micropaso Z",
    "Babystep Z",
    "Babystep Z",
    "Babystep Z",
	"Babystep Z"
};

const char MMSG_BABYSTEP_TIP[8][210] = {
	"点击按钮，可以按0.05mm间隔微调喷头高度.\r\n请谨慎使用该功能, 以防损坏模型或打印机.",
	"Click the button to fine-tune the height of the nozzle in 0.05mm intervals. Please use this function carefully to prevent damage to the model or printer.",
	"ボタンをクリックして, ノズルの高さを0.05mm間隔で微調整します. モデルやプリンターの損傷を防ぐため, この機能を慎重に使用してください.",
	"Haga clic en el botón para ajustar la altura de la boquilla en intervalos de 0,05 mm. Utilice esta función con cuidado para evitar da?os en el modelo o la impresora.",
	"Cliquez sur le bouton pour régler avec précision la hauteur de la buse par intervalles de 0,05 mm. Veuillez utiliser cette fonction avec précaution pour éviter d'endommager le modèle ou l'imprimante.",
	"Klicken Sie auf die Schaltfl?che, um die H?he der Düse in Intervallen von 0,05 mm fein einzustellen. Bitte verwenden Sie diese Funktion sorgf?ltig, um Sch?den am Modell oder Drucker zu vermeiden.",
	"Fare clic sul pulsante per regolare con precisione l'altezza dell'ugello a intervalli di 0,05 mm. Utilizzare questa funzione con attenzione per evitare danni al modello o alla stampante.",
	"Klik op de knop om de hoogte van het mondstuk in stappen van 0,05 mm af te stellen. Gebruik deze functie zorgvuldig om schade aan het model of de printer te voorkomen."
};

const char MMSG_SETTING_AUTOSWITCH[8][30]  = {
	"  自动切换喷头",
	"  Auto Switch",
	"  オートスイッチ",
	"    Cambiar",
    "   Detecteur",
    "   Schalter",
    "  Interruttore",
	"   Schakelaar"
};

const char MMSG_SETTING_MANUALSWITCH[8][30]  = {
	"  手动切换喷头",
	" Manually Switch",
	"  手動スイッチ",
	"    Manual",
    "    Manuel",
    "   Handbuch",
    "   Manuale",
	"  Handleiding"
};

const char MMSG_TITLE_MANUALSWITCH[8][40]  = {
	"手动切换喷头",
	"Manually Switch Nozzle",
	"手動でノズルを切り替える",
	"Cambiar manualmente la boquilla",
    "Changer manuellement de buse",
    "Düse manuell wechseln",
    "Cambia ugello manualmente",
	"Handmatig van mondstuk wisselen"
};

#endif // 
