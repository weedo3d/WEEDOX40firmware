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

#ifndef WT_HELPL_DOC_H
#define WT_HELPL_DOC_H

//TIP01 文件选择界面
const char HELP_TIP01_LINE[8][330] PROGMEM = {
	"本界面显示TF卡中的打印文件\r\n点击文件名, 开始打印\r\n点击返回按钮, 返回主界面\r\n点击上一步或下一步, 显示更多文件.",
	"This menu displays the print file in TF card.\r\nClick on the filename to start printing.\r\nClick the back button to return to the main interface.\r\nClick the previous or next button to display more files.",
	"このメニューはTFカードの印刷ファイルを表示します.\r\nファイル名をクリックして印刷を開始します.\r\n戻るボタンをクリックしてメインインターフェースに戻ります.\r\n他のファイルを表示するには, 前へまたは次へボタンをクリックします.",
	"Este menú muestra el archivo de impresión en la tarjeta TF.\r\nHaga clic en el nombre del archivo para comenzar a imprimir.\r\nHaga clic en el botón Atrás para volver a la.\r\nHaga clic en el nombre del archivo para comenzar a interfaz principal.\r\nHaga clic en el botón anterior o siguiente para mostrar más archivos.",
    "Ce menu affiche le fichier d'impression sur la carte TF.\r\nCliquez sur le nom du fichier pour lancer l'impression.\r\nCliquez sur le bouton retour pour revenir à l'interface principale.\r\nCliquez sur le bouton précédent ou suivant pour afficher plus de fichiers.",
    "Dieses Menü zeigt die Druckdateien auf der MicroSD-Karte an.\r\nWahlen Sie einen Dateinamen um einen Druck zu starten.\r\nHauptmenü um ins Hauptmenü zurückzukehren.\r\nzurück oder weiter um weitere Dateien anzuzeigen.",
    "Questo menu visualizza il file di stampa nella scheda TF.\r\nFare clic sul nome del file per avviare la stampa.\r\nFare clic sul pulsante Indietro per tornare all'interfaccia principale.\r\nFare clic sul pulsante precedente o successivo per visualizzare più file.",
    "Dit menu geeft de print bestanden weer op de TF kaart.\r\nDruk op de filenaam om het printen te starten.\r\nDruk op Terug om terug te keren naar het hoofdmenu.\r\nDruk op Vorige of Volgende om de overige bestanden weer te geven."
};

// TIP02 打印文件界面
const char HELP_TIP02_LINE[8][460] PROGMEM = {
	"本界面显示当前打印的文件名, 及打印机的各项状态数据.\r\n打印剩余时间为预估, 与实际剩余时间会有一定的出入.\r\n点击暂定按钮, 打印任务暂停.\r\n点击设置按钮, 进入打印参数设置界面.\r\n点击关闭按钮, 当前打印任务将中止.",
	"This screen displays the information of current job.\r\nThe remaining time is estimated, it may be some\r\ndifferent from the actual remaining time.\r\nClick the pause button to pause the print job.\r\nClick the settings button to goto the print parameters\r\nsettings screen.\r\nClick the quit button to abort the current job.",
	"この画面には現在のジョブの情報が表示されます.\r\n残り時間は概算であり,実際の残り時間とは多少異なる場合があります.\r\n印刷ジョブを一時停止するには, 一時停止ボタンをクリックします. \r\n設定ボタンをクリックして, 印刷パラメータ設定画面に進みます.\r\n現在のジョブを中止するには, 閉じるボタンをクリックします.",
	"Esta pantalla muestra la información del trabajo actual.\r\nEl tiempo restante es estimado, puede ser algo diferente del tiempo restante real.\r\nHaga clic en el botón de pausa para pausar el trabajo deimpresión.\r\nHaga clic enel botón de configuración para ir a la pantallade configuraciónde los parámetros de impresión.\r\nHaga clic en el botón de cerrar para abortar el trabajo actual.",
    "Cet écran affiche les informations du travail en cours.\r\nLe temps restant est estimé, il peut être quelque peu différent du temps restant réel.\r\nCliquez sur le bouton pause pour interrompre le travail d'impression.\r\nCliquez sur le bouton Paramètres pour accéder à l'écran des paramètres d'impression.\r\nCliquez sur le bouton Quitter pour abandonner le travail en cours.",
    "Hier sehen Sie Informationen zum aktuellen Druckauftrag.\r\nDie verbleibende Zeit ist geschatzt und kann von der real verbleibenden Zeit abweichen.\r\nPause um den Druck zu pausieren.\r\nEinstellungen um die aktuellen Druckparameter anzuzeigen\r\nAbbrechen  um den aktuellen Druck abzubrechen.",
    "Questa schermata visualizza le informazioni del lavoro corrente.\r\nIl tempo rimanente è stimato, potrebbe essere leggermente diverso dal tempo rimanente effettivo.\r\nFare clic sul pulsante di pausa per sospendere il lavoro di stampa.\r\nFare clic sul pulsante delle impostazioni per accedere alla schermata delle impostazioni dei parametri di stampa.\r\nFare clic sul pulsante Esci per interrompere il lavoro corrente.",
    "Dit scherm geeft informatie over de huidige printtaak.r\nDe resterende tijd wordt weergegeven. Deze kan afwijken en is slechts indicatief.\r\nDruk op Pauze om de huidige printtaak te pauzeren.\r\nDruk op Instellingen om naar het printer instellingen menu te gaan.\r\nDruk op Stop om de huidige printtaak af te breken."
};

// TIP03 打印参数设置界面
const char HELP_TIP03_LINE1[8][195] PROGMEM = {
	"料丝操作: 载入或卸载料丝\r\n温度设置: 改变喷头或热床的温度\r\n速度设置: 调节打印速度",
	"Filament Operation: feeding or retracting the filament\r\nTemperature: adjust the temp of the nozzle or bed\r\nSpeed: adjust the printing speed",
	"フィラメント操作: フィラメントの供給または収縮\r\n温度設定: ノズルまたはベッドの温度を調整する\r\nスピード設定: 印刷速度を調整します",
	"Filamento: alimentación o retracción del filamento.\r\nTemperatura: ajustar la temperatura de la boquilla o cama.\r\nVelocidad: ajustar la velocidad de impresión.",
    "Fonctionnement du filament: alimentation ou rétraction du filament\r\nTempérature: ajustez la température de la buse ou du lit\r\nVitesse: ajustez la vitesse d'impression",
    "Filamenteinstellungen: Laden und Entladen von Filament\r\nTemperatur: Einstellen der Temperatur von Düse und Druckbett\r\nGeschwindigkeit: Einstellen der Druckgeschwindigkeit",
    "Funzionamento del filamento: alimentazione o ritiro del filamento\r\nTemperatura: regola la temperatura dell'ugello o del letto\r\nVelocità: regola la velocità di stampa",
    "Filament bediening: Invoer of Terugvoer van het filament\r\nTemperatuur: pas bed of printkop temperatuur aan\r\nSnelheid: pas de printsnelheid aan"
};

const char HELP_TIP03_LINE2[8][180] PROGMEM = {
	"打印完成关机: 打开或关闭打印完自动关机功能\r\n料丝检测: 启用或禁用料丝检测功能.\r\n微调Z轴: 实时调节Z轴高度.",
	"Auto Power Off: Automatic shutdown after printing.\r\nRunout Sensor: filament detection.\r\nBabystep Z: Adjust the z axis in real-time.",
	"プリントオフ: 印刷後の自動シャットダウン.\r\n振れセンサー：フィラメント検出.\r\nZジク ビドウ: リアルタイムでz軸を調整します.",
	"Apagado automático: apagado automático después de imprimir.\r\nRunout Sensor: detección de filamento.\r\nMicropaso Z: Ajusta el eje z en tiempo real.",
    "Arrêt automatique: arrêt automatique après l'impression.\r\nCapteur de voile: détection de filament.\r\nBabystep Z: Ajustez l'axe z en temps reel.",
    "Auto Power Off: Drucker nach vollendetem Druck ausschalten.\r\nFilamentsensor: Prüft auf vorhandenes Filament.\r\nBabystep Z: Passen Sie die Z-Achse in Echtzeit an.",
    "Spegnimento automatico: spegnimento automatico dopo la stampa.\r\nSensore di runout: rilevamento del filamento.\r\nBabystep Z: Regola l'asse z in tempo reale.",
    "Auto Power Off: Zet printer automatisch uit na het printen.\r\nRunout Sensor: filament detectie.\r\nBabystep Z: Pas de z-as in realtime aan."
};

const char HELP_TIP03_LINE3[8][390] PROGMEM = {
	"自动切换喷头: 检测到断丝后, 自动切换到另一个喷头继续打印.\r\n手动切换喷头: 手动切换至另一个喷头继续打印.\r\n保存关机: 保存当前打印任务并自动关机, 重新上电后可以继续打印",
	"Auto Switch: After filament runout, it will automatically switch to another nozzle to resume the printing job.\r\nManual Switch: Manually switch to another nozzle to continue printing.\r\nSave&Off: Save the current job and shut down, you can resume the printing after powering up again.",
	"オートスイッチ: フィラメントがなくなった後, 自動的に別のノズルに切り替わり, 印刷ジョブを再開します.\r\n手動スイッチ: 手動で別のノズルに切り替えて, 印刷を続行します.\r\n印刷を保存: 現在のジョブを保存してシャットダウンします. 電源を入れ直すと印刷を再開できます.",
	"Cambiar: Despues de que se agote el filamento, cambiara automáticamente a otra boquilla para reanudar el trabajo de impresion.\r\nManual: Cambie manualmente a otra boquilla para continuar imprimiendo.\r\nGuardar impresión: guarde el trabajo actual y cierre,puede reanudar la impresión después de volver a encenderlo.",
    "Detecteur: Despues de que se agote el filamento, cambiara automáticamente a otra boquilla para reanudar el trabajo de impresion.\r\nManuel: Basculez manuellement vers une autre buse pour continuer l'impression.\r\nEnregistrer et désactiver: enregistrez le travail en cours et arrêtez, vous pouvez reprendre l'impression après la mise sous tension.",
    "Schalter: Nach Ablauf des Filaments wird automatisch auf eine andere Duse umgeschaltet, um den Druckauftrag fortzusetzen.\r\nHandbuch: Wechseln Sie manuell zu einer anderen Duse, um mit dem Drucken fortzufahren.\r\nSpeichern&Ausschalten: Speichere den aktuellen Druckauftrag und schalte den Drucker aus. Der Druck kann nach Wiedereinschalten des Druckers fortgesetzt werden.",
    "Interruttore: Dopo l'esaurimento del filamento, passerà automaticamente a un altro ugello per riprendere il lavoro di stampa.\r\nManuale: Passare manualmente a un altro ugello per continuare a stampare.\r\nSalva e spegni: salva il lavoro corrente e chiudi, puoi riprendere la stampa dopo l'accensione.",
    "Schakelaar: Als het filament op is, schakelt het automatisch over naar een ander mondstuk om de afdruktaak te hervatten.\r\nHandleiding: Schakel handmatig over naar een ander mondstuk om door te gaan met afdrukken.\r\nOpslaan&Uitzetten: Sla huidige printopdracht op en zet uit, na herstarten kan de printopdracht hervat worden."
};


// TIP04 打印速度设置界面
const char HELP_TIP04_LINE[8][315] PROGMEM = {
	"本界面可调节当前打印任务的打印速度.\r\n请注意: 打印速度设置过快会明显降低打印质量.\r\n请尽量使用切片软件中的高速模式来缩短打印时间.",
	"This menu can adjust the printing speed of the current\r\njob.\r\nNotice: Printing speed settings too fast will significantly\r\nreduce the print quality.\r\nPlease try to use the high speed mode in the slicing\r\nsoftware to shorten the printing time.",
	"このインターフェイスでは, 現在の印刷ジョブの印刷速度を調整できます.\r\n注意：印刷速度の設定が速すぎると, 印刷品質が大幅に低下します.\r\n印刷時間を短縮する高速モードのスライスでソフトウェアを使用してみてください.",
	"Esta interfaz puede ajustar la velocidad de impresión del trabajo de impresión actual.\r\nNota: La velocidad de impresión es demasiado rápido reducirá significativamente la calidad de impresión.\r\nIntente utilizar el modo de alta velocidad en el software de corte para acortar el tiempo de impresión.",
    "Ce menu peut régler la vitesse d'impression du travail en cours.\r\nRemarque: des paramètres de vitesse d'impression trop rapides réduiront considérablement la qualité d'impression.\r\nVeuillez essayer d'utiliser le mode haute vitesse dans le logiciel de tranchage pour raccourcir le temps d'impression.",
    "Hier kann die Druckgeschwindigkeit für den aktuellen Druckjob angepasst werden\r\nAnmerkung: Eine zu hohe Druckgeschwindigkeit führt zu eingeschrankter Druckqualitat.\r\nBitte versuchen Sie moglichst die Druckgeschwindigkeit über die Slicingsoftware einzustellen um die Druckzeiten zu reduzieren.",
    "Questo menu può regolare la velocità di stampa del lavoro corrente.\r\nAvviso: impostazioni di velocità di stampa troppo elevate ridurranno notevolmente la qualità di stampa.\r\nProva a utilizzare la modalità ad alta velocità nel software di slicing per abbreviare il tempo di stampa.",
    "In dit menu kun je de printsnelheid aanpassen.\r\nLet op: te hoge printsnelheden hebben een nadelige invloed op de printkwaliteit.\r\nGebruik bij voorkeur de high speed mode in de slicing software om de printtijd te verkorten."
};

// TIP05 开机自检界面
const char HELP_TIP05_LINE[8][280] PROGMEM = {
	"喷头或热床无法读取温度或无法加热故障: 请检查喷头或热床的接线是否松动.\r\nX,Y,Z轴无法归位故障: 如果喷头未运动, 请检查电机接线是否松动. 如果喷头运行到原点位置后未停止, 请检查限位开关是否损坏, 或是接线是否松动.",
	"Temperature can't be read or heating fail: Please check if the cable of the nozzle or the bed is loose.\r\nX, Y, Z axis homing fault: If the nozzle is not moving,\r\nplease check if the motor cable is loose.",
	"温度が読み取れない, または加熱が失敗する:ノズルまたはベッドのケーブルが緩んでいないか確認してください.\r\nX, Y, Z軸の原点復帰不良：ノズルが動かない場合は, モーターケーブルが緩んでいないか確認してください.",
	"La temperatura no se puede leer o la calefacción falla: compruebe si el cable de la boquilla o la cama están flojos.\r\nFalla de referencia del eje X, Y, Z: si la boquilla no se mueve, compruebe si el cable del motor está suelto.",
    "La température ne peut pas être lue ou le chauffage échoue: veuillez vérifier si le cable de la buse ou le lit est lache.\r\nDéfaut de référence des axes X, Y, Z: Si la buse ne bouge pas, veuillez vérifier si le cable du moteur est lache.",
    "Temperatur kann nicht ermittelt werden oder Aufheizen war fehlerhaft: Prüfen Sie ob das Kabel von Düse und/oder Heizbett evtl. lose ist.\r\nX, Y, Z-Achsenfehler (Startposition): Wenn sich die Düse nicht bewegt, prüfen Sie bitte ob das entsprechende Motorkabel lose ist.",
    "Impossibile leggere la temperatura o il riscaldamento non funziona: controllare se il cavo dell'ugello o del letto è allentato.\r\nErrore di homing sugli assi X, Y, Z: Se l'ugello non si muove, controllare se il cavo del motore è allentato.",
    "Temperatur kan niet worden afgelezen of opwarm defect: Controlleer of de kabel van de printkop of het printbed los zit.\r\nX,Y,Z as homing fout: als de printkop niet beweegt, controlleer of de motor kabel los zit."
};

// TIP06 维护界面1
const char HELP_TIP06_LINE[8][270] PROGMEM = {
	"自动进丝: 自动加热喷头并载入料丝.\r\n自动退丝: 自动加热喷头并退出料丝.\r\n手动加热: 手动设置喷头和热床的温度并加热.",
	"Filament Feed: Automatic heating of the nozzle and loading of the filament.\r\nFilament Retract: Automatically heats the nozzle and retract the filament.\r\nPreheat: Set the temperature of the nozzle or bed and heating.",
	"自動ワイヤ送り: ノズルの自動加熱とフィラメントの装填.\r\n自動ワイヤ除去: ノズルを自動的に加熱し, フィラメントを収縮させます.\r\n手動加熱：ノズルとホットベッドの温度を手動で設定し, 加熱します.",
	"Entrada de filamento: calentamiento automático de la boquilla y carga del filamento.\r\nSalida de filamento: calienta automáticamente la boquilla y retrae el filamento.\r\nPrecalentar: ajuste la temperatura de la boquilla y la cama y la calefacción.",
    "Filament Feed: Chauffage automatique de la buse et chargement du filament.\r\nRétraction du filament: chauffe automatiquement la buse et rétracte le filament.\r\nPréchauffer: régler la température de la buse ou du lit et le chauffage.",
    "Filament laden: Automatisches aufheizen der Düse und laden des Filaments.\r\nFilament entladen: Automatisches aufheizen der Düse und entladen des Filaments.\r\nVorheizen: Einstellen der Düsen und Druckbetttemperatur und anschliebendes Aufheizen.",
    "Alimentazione del filamento: riscaldamento automatico dell'ugello e caricamento del filamento.\r\nFilament Retract: riscalda automaticamente l'ugello e ritrae il filamento.\r\nPreriscaldamento: impostare la temperatura dell'ugello o del letto e del riscaldamento.",
    "Filament Invoer: Automatisch opwarmen van de printkop en inladen van het filament.\r\nFilament Terugvoer: Automatisch opwarmen van de printkop en terugvoeren van het filament\r\nOpwarmen: Stel de temperatuur van de printkop en bed in."
};

// TIP07 维护界面2
const char HELP_TIP07_LINE[8][355] PROGMEM = {
	"点动模式: 喷头归位, 以及手动控制XYZ方向的运动.\r\n平台校准: 对打印平台的水平度进行调节, 使其平行于喷头运行的XY平台.\r\nZ轴偏置: 微调喷头与平台的相对高度, 可调大或调小打印时喷头与平台的间隙.",
	"Jog Mode: Homing and manual control of XYZ motion.\r\nLevel Bed: Adjust the level of the printing platform so\r\nthat it is parallel to the XY stage of the nozzle.\r\nZ Offset: Fine-tune the relative height of the nozzle and\r\nthe platform, it can adjust the gap between the nozzle and the platform when printing.",
	"ジョグモード: XYZ動作の原点復帰と手動制御.\r\nレベルベッド: 印刷プラットフォームの高さを調整して, ノズルのXYステージと平行になるようにします.\r\nZオフセット: ノズルとプラットフォームの相対的な高さを微調整します. 印刷時にノズルとプラットフォームの間のギャップを調整できます.",
	"Modo de jog: Homing y control manual de movimiento XYZ.\r\nNivelar plataforma: ajuste el nivel de la plataforma de impresión de modo que quede paralelo a la etapa XY de la boquilla.\r\nDesfase Z: ajuste la altura relativa de la boquilla y la plataforma, puede ajustar el espacio entre la boquilla y la plataforma al imprimir.",
    "Mode Jog: Prise de référence et controle manuel du mouvement XYZ.\r\nLit de niveau: ajustez le niveau de la plate-forme d'impression de sorte qu'il soit parallèle à l'étage XY de la buse.\r\nDécalage Z: affinez la hauteur relative de la buse et de la plate-forme, il peut ajuster l'écart entre la buse et la plate-forme lors de l'impression.",
    "Achsenbewegungen: Startposition und manuelles Bewegen der XYZ-Achsen.\r\nDruckbett leveln: Druckbett so einstellen, dass dieses parallel zur XY-Achse verlauft.\r\nZ-Versatz (Offset): Feineinstellung der relativen Hohe von Düse und Druckbett, so dass beim Drucken Unebenheiten automatisch ausgeglichen werden konnen.",
    "Modalità Jog: Homing e controllo manuale del movimento XYZ.\r\nPiano orizzontale: regolare il livello della piattaforma di stampa in modo che sia parallela alla fase XY dell'ugello.\r\nZ Offset: regola l'altezza relativa dell'ugello e della piattaforma, può regolare lo spazio tra l'ugello e la piattaforma durante la stampa.",
    "Jog Modus: Homing en handmatige besturing van XYZ beweging.\r\nBed Afstellen: Pas het printplatform aan zodat deze parallel loopt aan de XY assen van de printkop.\r\nZ Marge: Finetunen van de afstand van de printkop tot het printbed. Afstellen tijdens het printen is mogelijk."
};

// TIP08 维护界面3
const char HELP_TIP08_LINE[8][298] PROGMEM = {
	"接近开关高度调节: 调节接近开关与喷头的相对位置. 接近开关过高, 会导致自动调平时喷头与平台撞击. 接近开关过低, 打印时容易刮到模型.\r\n关闭电机: 电机打开时, 位置会被锁定无法移动. 当你需要手动调节喷头或平台的位置时, 需要首先关闭电机, 解除电机的锁定.",
	"Proximity Height: Adjust the relative position of the proximity switch to the nozzle.\r\nMotor Off: When the motor is turned on, the position is\r\nlocked and cannot be moved.",
	"近接の高さ: 近接スイッチとノズルの相対位置を調整します.\r\nモーターを切る: モーターの電源を入れると, 位置がロックされて動かなくなります手動でノズルまたはプラットフォームの位置を調整する必要がある場合は, 最初にモーターをオ",
	"Proximidad: ajuste la posición relativa del interruptor de proximidad al cabezal rociador. \r\nMotor apagado: cuando el motor está encendido, la posición se bloquea y no se puede mover.",
    "Hauteur de proximité: ajustez la position relative du commutateur de proximité par rapport à la buse.\r\nMoteur éteint: lorsque le moteur est allumé, la position est verrouillée et ne peut pas être déplacée.",
    "Hohe des Annaherungssensors: Justieren der relativen Position von Annaherungssensor und Düse.\r\nDüsenversatz: Ausrichten der beiden Düsen zueinander für ein einwandfreies Druckbild.\r\nMotoren deaktivieren: Motoren deaktivieren um die Achsen frei per Hand bewegen zu konnen.",
    "Altezza di prossimità: regola la posizione relativa dell'interruttore di prossimità rispetto all'ugello.\r\nMotore spento: quando il motore è acceso, la posizione è bloccata e non può essere spostata.",
    "Hoogte-sensor Hoogte: Pas de relatieve positie van de sensor aan tov de printkop.\r\nPrintkop Marge: Pas de afstanden tussen beide printkoppen aan om te zorgen dat prints uit beide printkoppen met elkaar uitlijnen.\r\nMotor Uit: Als de motor is ingeschakeld, wordt de positie vergrendeld."
};

// TIP09 手动加热界面
const char HELP_TIP09_LINE[8][305] PROGMEM = {
	"对喷头和平台进行一起加热, 或是仅加热其中的一其.\r\n不需要加热的项目, 可将温度设置为0.\r\n点击确定, 开始加热.\r\n点击取消, 关闭加热并返回.",
	"The nozzle and the bed are heated together or only\r\none of them is heated.\r\nFor item that do not require heating, set the temperature to zero.\r\nClick OK to start heating.\r\nClick Cancel to turn off heating and return.",
	"ノズルとベッドは一緒に加熱されるか, またはそれらの一方だけが加熱される.\r\n加熱を必要としない品目については, 温度をゼロに設定してください.\r\n加熱を開始するにはOKボタンをクリックしてください.\r\n加熱をオフにして戻るには, キャンセル]ボタンをクリックします.",
	"La boquilla y la cama se calientan juntas o solo una de ellas se calienta.\r\nPara los artículos que no requieren calefacción, ajustela temperatura a cero.\r\nHaga clic en el botón Aceptar para iniciar elcalentamiento.\r\nHaga clic en el botón Cancelar para apagar la calefacción y volver.",
    "La buse et le lit sont chauffés ensemble ou un seul d'entre eux est chauffé.\r\nPour les articles qui ne nécessitent pas de chauffage, réglez la température sur zéro.\r\nCliquez sur OK pour démarrer le chauffage.\r\nCliquez sur Annuler pour désactiver le chauffage et le retour.",
    "Hier die Temperatur für Druckbett und Düsen einstellen\r\nSoll eine Düse und/oder das Druckbett nicht geheizt werden, dann hierfür jeweils die Temperatur auf 0 einstellen\r\nOK startet das Aufheizen\r\nAbbruch beendet das Menü ohne Parameter zu andern.",
    "L'ugello e il letto vengono riscaldati insieme o solo uno di essi viene riscaldato.\r\nPer gli articoli che non richiedono riscaldamento, impostare la temperatura a zero.\r\nFare clic su OK per avviare il riscaldamento.\r\nFare clic su Annulla per spegnere il riscaldamento e tornare.",
    "De printkop en het printbed worden beide opgewarmd of enkel een van beide.\r\nVoor onderdelen die niet hoeven te worden opgewarmd, stel deze in op 0 graden.\r\nDruk op OK op op te warmen.\r\nDruk op Annuleer om verwarming uit te schakelen en terug te keren."
};

// TIP10 点动模式界面
const char HELP_TIP10_LINE[8][370] PROGMEM = {
	"点击X左边的按钮, 喷头向左移动, 三个按钮的移动距离分别是50mm, 10mm, 1mm.\r\n点击Y左边的按钮, 平台向前移动, 三个按钮的移动距离分别是50mm, 10mm, 1mm.\r\n点击Z左边的按钮, 平台向上移动, 三个按钮的移动距离分别是10mm, 1mm, 0.1mm.",
	"Click the left button of X, the nozzle moves to the left, the distance of the three buttons is 50mm, 10mm and 1mm.\r\nClick the left button of Y, the bed moves forward,\r\nthe distance is same as X.\r\nClick the left button of Z. the bed moves upwards. The distance is 10mm, 1mm amd 0.1mm.",
	"Xの左ボタンをクリックすると, ノズルが左に移動し, 3つのボタンの距離は50 mm, 10 mm, 1 mmです.\r\nYの左ボタンをクリックすると, ベッドが前方に移動します.距離はXと同じです.\r\nZの左ボタンをクリックすると, ベッドが上に移動します距離は10mm, 1mm, 0.1mmです.",
	"Haga clic en el botón izquierdo de X, la boquilla se mueve hacia la izquierda, la distancia de los tres botones es de 50mm, 10mm y 1mm.\r\nHaga clic en el botón izquierdo de Y, la cama se mueve hacia adelante, la distancia es la misma que X.\r\nHaga clic en el botón izquierdo de Z. la cama se mueve hacia arriba. La distancia es de 10mm, 1mm amd 0.1mm.",
    "Cliquez sur le bouton gauche de X, la buse se déplace vers la gauche, la distance des trois boutons est de 50 mm, 10 mm et 1 mm.\r\nCliquez sur le bouton gauche de Y, le lit avance, la distance est la même que X.\r\nCliquez sur le bouton gauche de Z, le lit se déplace vers le haut. La distance est de 10 mm, 1 mm et 0,1 mm.",
    "Die Pfeile bewegen jeweils die X- und Y-Achsen um 50mm, 10mm und 1mm in Pfeilrichtung.\r\nDie Z-Achse bewegt sich entsprechend, aber um jeweils 10mm, 1mm und 0.1mm rauf und runter.",
    "Fare clic sul pulsante sinistro di X, l'ugello si sposta a sinistra, la distanza dei tre pulsanti è 50 mm, 10 mm e 1 mm.\r\nFare clic sul pulsante sinistro di Y, il letto si sposta in avanti, la distanza è la stessa di X.\r\nFare clic sul pulsante sinistro di Z, il letto si sposta verso l'alto. La distanza è di 10 mm, 1 mm e 0,1 mm.",
    "De knoppen links van X bewegen de printkop naar links. De afstanden zijn 50mm, 10mm en 1mm.\r\nDe knoppen links van Y bewegen het printbed naar voren,\r\nde afstanden zijn gelijk aan X.\r\nDe knoppen links van Z bewegen het printbed naar boven. De afstanden zijn 10mm, 1mm en 0.1mm."
};

// TIP11 设置界面1
const char HELP_TIP11_LINE[8][280] PROGMEM = {
	"Wifi网络设置: 配置Wifi网络, 以及Wifi设备OTA升级.\r\n语言设置: 设置界面的显示语言.\r\n设备信息: 显示设备的打印时间和版本信息.",
	"Wifi Setting: Configuring Wifi network, and Wifi device OTA upgrade.\r\nLanguage Setting: Set the display language of the interface.\r\nMachine Info: Display device print time and version.",
	"無線LAN設定: Wifiネットワークの設定, およびWifiデバイスのOTAアップグレード. \r\n言語設定: インターフェースの表示言語を設定します. \r\nデバイス情報: デバイスの印刷時間とバージョン情報を表示します.",
	"Red wifi: configuración de la red Wifi y actualización de OTA del dispositivo Wifi.\r\nIdioma: establece el idioma de visualización de lainterfaz\r\nInformacion: muestra el tiempo de impresión deldispositivo y la información de la versión.",
    "Paramètres Wifi: configuration du réseau Wifi et de la mise à niveau OTA du périphérique Wifi.\r\nRéglage de la langue: définissez la langue d'affichage de l'interface.\r\nInfo machine: affiche l'heure et la version d'impression du périphérique.",
    "Wifi Einstellungen: Konfiguration der Wifi Verbindung, und des OTA Wifi Gerateupgrades.\r\nSpracheinstellungen: Auswahl der Sprache, in der die Bedienoberflache angezeigt wird.\r\nGerate Info: Zeigt Infos zu Gerateversion und Gesamtdruckzeit des Druckers an.",
    "Impostazioni Wi-Fi: configurazione della rete Wi-Fi e aggiornamento OTA del dispositivo Wi-Fi.\r\nImpostazione lingua: consente di impostare la lingua di visualizzazione dell'interfaccia.\r\nInformazioni macchina: visualizza l'ora e la versione di stampa del dispositivo.",
    "WiFi Instelling: Configuratie van het WiFi netwerk, WiFi apparaat OTA upgrade.\r\nTaal Instelling: Stel gebruikte taal in van de user interface op het display.\r\nMachine Informatie:Toon totale printtijd en versie van de printer."
};


// TIP12 设置界面2
const char HELP_TIP12_LINE[8][250] PROGMEM = {
	"打印完成关机: 打印任务完成后自动关闭电源.\r\n料丝检测: 启用或禁用料丝检测功能.\r\n自动切换喷头: 检测到断丝后, 自动切换到另一个喷头继续打印.",
	"Auto Power Off: Automatic shutdown after printing.\r\nRunout Sensor: filament detection.\r\nAuto Switch: After filament runout, it will automatically switch to another nozzle to resume the printing job.",
	"プリントオフ: 印刷後の自動シャットダウン.\r\n振れセンサー：フィラメント検出.\r\nオートスイッチ: フィラメントがなくなった後, 自動的に別のノズルに切り替わり, 印刷ジョブを再開します.",
	"Apagado automático: apagado automático después de.\r\nRunout Sensor: detección de filamento.\r\nCambiar: Despues de que se agote el filamento, cambiara automáticamente a otra boquilla para reanudar el trabajo de impresion.",
    "Arrêt automatique: arrêt automatique après l'impression.\r\nCapteur de voile: détection de filament.\r\nDetecteur: Despues de que se agote el filamento, cambiara automáticamente a otra boquilla para reanudar el trabajo de impresion.",
    "Auto Power Off: Schaltet den Drucker nach Beendigung des Druckes aus.\r\nFilamentsensor: Prüft auf vorhandenes Filament.\r\nSchalter: Nach Ablauf des Filaments wird automatisch auf eine andere Duse umgeschaltet, um den Druckauftrag fortzusetzen.",
    "Spegnimento automatico: spegnimento automatico dopo la stampa.\r\nSensore di runout: rilevamento del filamento.\r\nInterruttore: Dopo l'esaurimento del filamento, passerà automaticamente a un altro ugello per riprendere il lavoro di stampa.",
    "Auto Power Off: Zet printer automatisch uit na het printen.\r\nRunout Sensor: filament detectie.\r\nSchakelaar: Als het filament op is, schakelt het automatisch over naar een ander mondstuk om de afdruktaak te hervatten."
};

// TIP13 设置界面3
const char HELP_TIP13_LINE[8][440] PROGMEM = {
	"开机自检: 打印时启动时, 自动对主要部件进行检测.\r\n节电模式: 打印处于待机状态，且无操作时，在等待一段时间后自动关闭电源，以节约能源.\r\n固件参数: 保存, 读取或恢复固件参数.",
	"Post: Automatic testing the main parts when printer power on.\r\nPower Save Mode: When printing is in standby mode and there is no operation, it will automatically turn off the power after waiting for a period of time to save energy.\r\nFirmware Parameters: save, load or restore firmware parameters.",
	"セルフテスト: プリンタの電源が入ったときに主要部品を自動的にテストします.\r\n節電モード: 印刷待機中に何も操作しないときは, 一定時間待ってから自動的に電源が切れます.\r\nファームウェアパラメーター：ファームウェアパラメータを保存, ロード, または復元します.",
	"Autoprueba: Prueba automática de las partes principales cuando la impresora está encendida.\r\nAhorro de energía: cuando la impresión está en modo de espera y no se realiza ninguna operación, se apagará automáticamente después de esperar un período de tiempo para ahorrar energía.\\r\nParámetros del firmware: guardar, cargar o restaurar parámetros de firmware.",
    "Post: test automatique des pièces principales lors de la mise sous tension de l'imprimante.\r\nMode d'économie d'énergie: lorsque l'impression est en mode veille et qu'aucune opération n'est effectuée, l'appareil s'éteindra automatiquement après avoir attendu pendant un certain temps pour économiser de l'énergie.\r\nParamètres du micrologiciel: enregistrez, chargez ou restaurez les paramètres du micrologiciel.",
    "Post: Testet den Drucker nach dem Einschalten zuerst automatisch auf etwaige Fehler.\r\nPower Save Mode: Um Strom zu sparen wird der Drucker ausgeschaltet, wenn er eine vorgegebene Zeit inaktiv ist.\r\nFirmware Parameter: speichern, laden oder wiederherstellen der FW-Parameter.",
    "Post: verifica automatica delle parti principali all'accensione della stampante.\r\nModalità risparmio energetico: quando la stampa è in modalità standby e non viene eseguita alcuna operazione, l'alimentazione verrà automaticamente disattivata dopo aver atteso un periodo di tempo per risparmiare energia.\r\nParametri firmware: salva, carica o ripristina i parametri del firmware.",
    "Post: Automatische controle van de belangrijkste printer onderdelen bij het aanzetten.\r\nPower Save Modus: Als de printer op standby staat en er geen activiteit gaande is, schakelt de printer zichzelf automatisch uit na de ingestelde tijdsduur om energie te besparen.\r\nFirmware Instellingen: Opslaan, Openen, of Terugzetten van firmware instellingen."
};


// TIP14 节电设置界面
const char HELP_TIP14_LINE[8][330] PROGMEM = {
	"打印处于待机状态, 且无操作时, 在等待一段时间后自动关闭电源, 以节约能源. 等待时间可设置从1分钟至30分钟.选择关闭将禁用节电功能.",
	"When printing is in standby mode and there is no operation, it will automatically turn off the power after waiting for a period of time to save energy. The waiting time can be set from 1 minute to 30 minutes. Selecting Off will disable the power save feature.",
	"印刷待機中に何も操作しないときは, 省エネのため一定時間待ってから自動的に電源が切れます. 待ち時間は1分から30分まで設定できます. オフを選択すると, 省電力機能が無効になります.",
	"Cuando la impresión está en modo de espera y no hay operación, se apagará automáticamente después de esperar un período de tiempo para ahorrar energía. El tiempo de espera se puede configurar desde 1 minuto hasta 30 minutos. Si selecciona Desactivado, se desactivará la función de ahorro de energía.",
    "Lorsque l'impression est en mode veille et qu'aucune opération n'est effectuée, l'appareil s'éteint automatiquement après avoir attendu un certain temps pour économiser de l'énergie. Le temps d'attente peut être réglé de 1 minute à 30 minutes. La sélection de Off désactivera la fonction d'économie d'énergie.",
    "Wenn der Drucker sich wegen Inaktivitat im Standby befindet  schaltet er sich nach vorgegebener Zeit selbsttatig ab um Strom zu sparen. Die Zeitdauer bis zum Abstellen kann von 1-30 Minuten eingestellt werden. Aus verhindert eine selbsttatige Abschaltung des Druckers.",
    "Quando la stampa è in modalità standby e non viene eseguita alcuna operazione, spegnerà automaticamente l'alimentazione dopo aver atteso un periodo di tempo per risparmiare energia. Il tempo di attesa può essere impostato da 1 minuto a 30 minuti. La selezione di Off disabiliterà la funzione di risparmio energetico.",
    "In standby modus, wanneer er geen printactie is, schakelt de printer automatisch uit na een door de gebruiker ingestelde tijdsperiode. Deze kan ingesteld worden tussen 1 en 30 minuten. Uitgeschakeld betekent dat deze functie niet actief is. De printer gaat dan niet automatisch in standby modus."
};

// TIP15 设置界面4
const char HELP_TIP15_LINE[8][96] PROGMEM = {
	"升级固件: 从TF卡升级固件.",
	"Upgrade: Upgrade firmware from TF card.",
	"更新する：TFカードからファームウェアをアップグレードします.",
	"Actualización: actualice el firmware de la tarjeta TF.",
    "Mise à niveau: mise à niveau du micrologiciel de la carte TF.",
    "Upgrade: Aktualisiert die FW mittels einer FW-Datei auf der eingelegten MicroSD-Karte.",
    "Aggiornamento: aggiorna il firmware dalla scheda TF.",
    "Upgrade: Upgrade de firmware vanaf de TF kaart."
};

//TIP21 WIFI盘界面
const char HELP_TIP21_LINE[8][490] PROGMEM = {
	"本界面显示WIFI盘中的打印文件\r\n通过网络发送到打印机中的文件保存在WIFI盘中\r\n点击文件名, 开始打印\r\n点击返回按钮, 返回主界面\r\n点击上一步或下一步, 显示更多文件.\r\n注意, 打印WIFI盘中文件时, 无法修改打印温度, 速度等参数.",
	"This menu displays the print file in WIFI Disk.\r\nFiles sent to the printer via the network are saved in the WIFI disk\r\nClick on the filename to start printing.\r\nClick the back button to return to the main interface.\r\nClick the previous or next button to display more files.\r\nNotice, when printing files in the WIFI disk, cannot modify the printing parameters.",
	"このメニューはTFカードの印刷ファイルを表示します. ネットワーク経由でプリンターに送信されたファイルはWIFIディスクに保存されますファイル名をクリックして印刷を開始します. 戻るボタンをクリックしてメインインターフェースに戻ります. 他のファイルを表示するには, 前へまたは次へボタンをクリックします.\r\nWIFIディスクにファイルを印刷する場合, 印刷パラメータを変更できないことに注意してください.",
	"Este menú muestra el archivo de impresión en la tarjeta TF. Haga clic en el nombre del archivo para comenzar a imprimir. Haga clic en el botón Atrás para volver a la. Haga clic en el nombre del archivo para comenzar a interfaz principal. Haga clic en el botón anterior o siguiente para mostrar más archivos.\r\nTenga en cuenta que al imprimir archivos en el disco WIFI, no se pueden modificar los parámetros de impresión.",
    "Ce menu affiche le fichier d'impression dans le disque WIFI. Les fichiers envoyés à l'imprimante via le réseau sont enregistrés sur le disque WIFI. Cliquez sur le nom du fichier pour lancer l'impression. Cliquez sur le bouton retour pour revenir à l'interface principale. Cliquez sur le bouton précédent ou suivant pour afficher plus de fichiers.\r\nRemarquez que lors de l'impression de fichiers sur le disque WIFI, vous ne pouvez pas modifier les paramètres d'impression.",
    "Zeigt die Dateien auf der WIFI-Disk an. Dateien die über das Netzwerk an den Drucker gesendet wurden werden auf der internen WIFI-Disk gespeichert. Klicke auf einen Dateinamen um den Druck zu starten. Klicke auf Hauptmenü um ins Hauptmenü zurück zu gelangen. zurück oder weiter um weitere Dateien anzuzeigen.\r\nBeachten Sie, dass beim Drucken von Dateien auf der WIFI-Festplatte die Druckparameter nicht geandert werden konnen.",
    "Questo menu visualizza il file di stampa in WIFI Disk. I file inviati alla stampante tramite la rete vengono salvati nel disco WIFI. Fare clic sul nome del file per avviare la stampa. Fare clic sul pulsante Indietro per tornare all'interfaccia principale. Fare clic sul pulsante precedente o successivo per visualizzare più file.\r\nNota, quando si stampano file nel disco WIFI, non è possibile modificare i parametri di stampa.",
    "Dit menu toont de bestanden op de WiFi kaart. Bestanden die naar de printer zijn gestuurd via het netwerk worden opgeslagen op de WiFI kaart. Druk op de filenaam om het printen te starten. Druk op Terug om terug te keren naar het hoofdmenu. Druk op Vorige of Volgende om de overige bestanden weer te geven.\r\nMerk op dat bij het afdrukken van bestanden op de WIFI-schijf, de afdrukparameters niet kunnen worden gewijzigd."
};


//TIP22 打印磁盘选择
const char HELP_TIP22_LINE[8][169] PROGMEM = {
    "TF卡: 显示TF卡中的打印文件.\r\nWIFI盘: 显示通过网络发送至WIFI盘中的打印文件.",
    "TF Card: Display the print files in the TF card.\r\nWIFI Disk: Display the print files sent to the WIFI disk via the wifi.",
    "TFカード：TFカード内の印刷ファイルを表示します.\r\nWIFIディスク：wifi経由でWIFIディスクに送信された印刷ファイルを表示します.",
    "Tarjeta TF: muestra los archivos de impresión en la tarjeta TF.\r\nDisco WIFI: muestra los archivos de impresión enviados al disco WIFI a través de wifi.",
    "Carte TF: affichez les fichiers d'impression sur la carte TF.\r\nDisque WIFI: affichez les fichiers d'impression envoyés au disque WIFI via le wifi.",
    "MicroSD: Zeigt die Druckdateien auf der MicroSD-Karte an\r\nWIFI Disk: Zeigt die Dateien an, die per WiFi an die WiFi-Disk im Drucker gesendet worden sind.",
    "Scheda TF: visualizza i file di stampa nella scheda TF.\r\nDisco WIFI: visualizza i file di stampa inviati al disco WIFI tramite il wifi.",
    "TF kaart: Toon de print bestanden op de TF kaart.\r\nWiFi kaart: Toon de print files op de WiFi kaart die zijn gestuurd via WiFi."
};

//TIP23 WIFI盘打印提示
const char HELP_TIP23_LINE[8][180] PROGMEM = {
    "抱歉, 打印WIFI盘中文件时, 无法修改打印温度, 速度等参数.",
	"Sorry, when printing files in the WIFI disk, you cannot modify the printing temperature, speed and other parameters.",
	"申し訳ありませんが, WIFIディスクにファイルを印刷する場合, 印刷温度, 速度, その他のパラメータを変更することはできません.",
	"Lo sentimos, al imprimir archivos en el disco WIFI, no puede modificar la temperatura de impresión, la velocidad y otros parámetros.",
	"Désolé, lors de l'impression de fichiers sur le disque WIFI, vous ne pouvez pas modifier la température d'impression, la vitesse et d'autres paramètres.",
	"Leider konnen Sie beim Drucken von Dateien auf der WIFI-Festplatte die Drucktemperatur, die Geschwindigkeit und andere Parameter nicht andern.",
	"Spiacenti, quando si stampano file nel disco WIFI, non è possibile modificare la temperatura di stampa, la velocità e altri parametri.",
	"Sorry, wanneer u bestanden afdrukt op de WIFI-schijf, kunt u de afdruktemperatuur, snelheid en andere parameters niet wijzigen."
};

const char DIAG_PAGE1_TITLE[8][30] PROGMEM = {
	"1. X1电机诊断",
	"1. X1 motor diagnosis",
 	"1. X1モーター",
	"1. Diagnóstico del motor X1",
    "1. Diagnostic du moteur X1",
    "1. Diagnose X1-Achsenmotor",
    "1. Diagnosi motore X1",
    "1. X1 motor diagnose"
};

const char DIAG_PAGE1_LINE[8][108] PROGMEM = {
	"请手动将左喷头移至平台的中间位置. 然后点击开始.",
	"Please manually move the left nozzle to the middle of\r\nthe platform. Then click start.",
	"左側のノズルを手動でプラットフォームの中央位置に移動してから, 開始をクリックしてください.",
	"Mueva manualmente la boquilla izquierda al centro de la\r\nplataforma. Luego haga clic en iniciar.",
    "Veuillez déplacer manuellement la buse gauche au milieu de la plate-forme. Cliquez ensuite sur démarrer.",
    "Bitte bewegen Sie die linke Düse per Hand zur Mitte des Druckbettes und klicken Sie dann auf Start.",
    "Si prega di spostare manualmente l'ugello sinistro al centro della piattaforma. Quindi fare clic su Start.",
    "Verplaats de linker printkop handmatig naar het midden en druk op Start."
};

const char DIAG_PAGE2_LINE[8][328] PROGMEM = {
	"左喷头将先向左移动5cm, 再向右移动5cm. 请观察喷头移动是否正常. \r\n如有异常, 请关闭打印机, 检查X电机和连线.",
	"The left nozzle will first move 5cm to the left and\r\nthen 5cm to the right. Please observe whether nozzle\r\nmoves normally. \r\nIf there is any abnormality, please turn off the printer\r\nand check the X motor and cable.",
 	"左のノズルは最初に5cm左に移動し, 次に5cm右に移動します. ノズルの動きが正常かどうかを確認してください.\r\n異常がある場合は、プリンタの電源を切り, Xモーターと接続を確認してください.",
	"La boquilla izquierda se moverá primero 5 cm hacia la izquierda y luego 5 cm hacia la derecha. Observe si la boquilla se mueve normalmente. Si hay alguna anomalía, apague la impresora y compruebe el motor X y el cable.",
    "La buse gauche se déplacera d'abord de 5 cm vers la gauche, puis de 5 cm vers la droite. Veuillez observer si la buse se déplace normalement. S'il y a une anomalie, veuillez éteindre l'imprimante et vérifier le moteur X et le cable.",
    "Die linke Düse wird sich um 5cm nach links und danach um 5cm nach rechts bewegen. Bitte beobachten Sie, ob die Bewegung normal und flüssig erfolgt.\r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den X-Achsenmotor und das entsprechende Kabel.",
    "L'ugello sinistro si sposterà prima di 5 cm a sinistra e poi di 5 cm a destra. Si prega di osservare se l'ugello si muove normalmente. In caso di anomalie, spegnere la stampante e controllare il motore X e il cavo.",
    "De linker printkop zal eerst 5cm naar links en dan 5cm naar rechts bewegen. Kijk of de printkop normaal beweegt.\r\nSchakel de printer meteen uit als dit niet het geval is en controlleer de X motor en kabel."
};


const char DIAG_PAGE3_TITLE[8][37] PROGMEM = {
	"2. X1限位开关诊断",
	"2. X1 endstop diagnosis",
 	"2. X1リミットスイッチ",
	"2. Diagnóstico de tope final X1",
    "2. Diagnostic de fin de course X1",
    "2. Diagnose X1-Endschalter",
    "2. Diagnosi del finecorsa X1",
    "2. X1 eindstop diagnose"
};

const char DIAG_PAGE3_LINE[8][280] PROGMEM = {
	"左喷头将向左移动至X1限位开关处. 请观察喷头向左移动至限位开关后是否立即停止.\r\n如有异常, 请关闭打印机, 检查X限位开关和连线.",
	"The left nozzle will move to the left to the X1 endstop. Please observe whether the nozzle stops immediately\r\nafter touching the endstop.\r\nIf there is an abnormality, please turn off the printer\r\nand check the X1 endstop and cable.",
 	"左のノズルはX1リミットスイッチまで左に移動しますので, 左に移動してすぐに停止するかどうかを確認してください. \r\n異常がある場合は, プリンターの電源を切り, Xリミットスイッチと配線を確認してください.",
	"La boquilla izquierda se moverá hacia la izquierda hasta el tope final X1. Observe si la boquilla se detiene inmediatamente después de tocar el tope final. Si hay alguna anomalía, apague la impresora y compruebe el interruptor de límite X y el cable.",
    "La buse de gauche se déplacera vers la gauche vers la butée X1. Veuillez observer si la buse s'arrête immédiatement après avoir touché la butée. S'il y a une anomalie, veuillez éteindre l'imprimante et vérifier la butée et le cable X1.",
    "Die linke Düse wird sich nach links an den X1-Endschalter bewegen. Bitte beobachten Sie, ob die Düse sofort bei Berührung des Endschalters stoppt\r\nWenn Sie irgendeine Unregelmabigkeit feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den X1-Endschalter.",
    "L'ugello sinistro si sposterà a sinistra sul finecorsa X1. Si prega di osservare se l'ugello si ferma immediatamente dopo aver toccato il finecorsa. Se c'è un'anomalia, spegnere la stampante e controllare il finecorsa X1 e il cavo.",
    "De linker printkop beweegt naar de X1 eindstop. Kijk of de printkop stopt zodra deze de eindstop raakt.\r\nAls dit niet gebeurt, zet dan de printer uit en controlleer de X1 eindstop en kabel."
};

const char DIAG_PAGE4_TITLE[8][30] PROGMEM = {
	"3. X2电机诊断",
	"3. X2 motor diagnosis",
 	"3. X2モーター",
	"3. Diagnóstico del motor X2",
    "3. Diagnostic du moteur X2",
    "3. Diagnose X2-Achsenmotor",
    "3. Diagnosi motore X2",
    "3. X2 motor diagnose"
};

const char DIAG_PAGE4_LINE[8][108] PROGMEM = {
	"请手动将右喷头移至平台的中间位置. 然后点击开始.",
	"Please manually move the right nozzle to the middle of\r\nthe platform. Then click start.",
 	"正しいノズルをプラットフォームの中央の位置に手動で移動してから, 開始をクリックしてください.",
	"Mueva manualmente la boquilla derecha al centro de la plataforma. Luego haga clic en iniciar.",
    "Veuillez déplacer manuellement la buse droite au milieu de la plate-forme. Cliquez ensuite sur démarrer.",
    "Bitte bewegen Sie die rechte Düse per Hand zur Mitte des Druckbettes und klicken Sie dann auf Start.",
    "Si prega di spostare manualmente l'ugello destro al centro della piattaforma. Quindi fare clic su Start.",
    "Verplaats de rechter printkop handmatig naar het midden en druk op Start."
};

const char DIAG_PAGE5_LINE[8][320] PROGMEM = {
	"右喷头将先向左移动5cm, 再向右移动5cm. 请观察喷头移动是否正常. \r\n如有异常, 请关闭打印机, 检查X电机和连线.",
	"The right nozzle will first move 5cm to the left and\r\nthen 5cm to the right. Please observe whether the movement of the nozzle is normal.\r\nIf there is any abnormality, please turn off the printer\r\nand check the X motor and cable.",
 	"右のノズルが最初に左に5cm, 次に右に5cm動きます. ノズルの動きが正常かどうかを確認してください. \r\n異常がある場合は, プリンタの電源を切り, Xモーターと接続を確認してください.",
	"La boquilla derecha se moverá primero 5 cm hacia la izquierda y luego 5 cm hacia la derecha. Observe si el movimiento de la boquilla es normal. Si hay alguna anomalía, apague la impresora y verifique el motor X y la conexión.",
    "La buse droite se déplacera d'abord de 5 cm vers la gauche, puis de 5 cm vers la droite. Veuillez observer si le mouvement de la buse est normal. S'il y a une anomalie, veuillez éteindre l'imprimante et vérifier le moteur X et le cable.",
    "Die rechte Düse wird sich um 5cm nach links und danach um 5cm nach rechts bewegen. Bitte beobachten Sie, ob die Bewegung normal und flüssig erfolgt.\r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den X-Achsenmotor und das entsprechende Kabel.",
    "L'ugello destro si sposterà prima di 5 cm a sinistra e poi di 5 cm a destra. Si prega di osservare se il movimento dell'ugello è normale. In caso di anomalie, spegnere la stampante e controllare il motore X e il cavo.",
    "De rechter printkop zal eerst 5cm naar links en dan 5cm naar rechts bewegen. Kijk of de printkop normaal beweegt.\r\nSchakel de printer meteen uit als dit niet het geval is en controlleer de X motor en kabel."
};

const char DIAG_PAGE6_TITLE[8][36] PROGMEM = {
	"4. X2限位开关诊断",
	"4. X2 endstop diagnosis",
 	"4. X2リミットスイッチ",
	"4. Diagnóstico del tope final X2",
    "4. Diagnostic de fin de course X2",
    "4. Diagnose X2-Endschalter",
    "4. Diagnosi del finecorsa X2",
    "4. X2 eindstop diagnose"
};

const char DIAG_PAGE6_LINE[8][275] PROGMEM = {
	"右喷头将向右移动至X2限位开关处. 请观察喷头向右移动至限位开关后是否立即停止.\r\n如有异常, 请关闭打印机, 检查X限位开关和连线.",
	"The right nozzle will move to the right to the X2 endstop. Please observe whether the nozzle stops immediately after touching the endstop.\r\nIf there is an abnormality, please turn off the printer and\r\ncheck the X2 endsotp and cable.",
 	"右のノズルがX2リミットスイッチの右に移動します.リミットスイッチの右に移動した直後にノズルが停止するか確認してください.\r\n異常がある場合は, プリンタの電源を切り, Xリミットスイッチと配線を確認してください.",
	"La boquilla derecha se moverá hacia la derecha hasta el tope final X2. Observe si la boquilla se detiene inmediatamente después de tocar el tope final. Si hay alguna anomalía, apague la impresora y compruebe el extremo y el cable X2.",
    "La buse droite se déplacera vers la droite jusqu'à la butée X2. Veuillez observer si la buse s'arrête immédiatement après avoir touché la butée. S'il y a une anomalie, veuillez éteindre l'imprimante et vérifier l'extrémité X2 et le cable.",
    "Die rechte Düse wird sich nach rechts an den X2-Endschalter bewegen. Bitte beobachten Sie, ob die Düse sofort bei Berührung des Endschalters stoppt\r\nWenn Sie irgendeine Unregelmabigkeit feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den X2-Endschalter.",
    "L'ugello destro si sposterà a destra sul finecorsa X2. Si prega di osservare se l'ugello si ferma immediatamente dopo aver toccato il finecorsa. Se c'è un'anomalia, spegnere la stampante e controllare l'estremità X2 e il cavo.",
    "De rechter printkop beweegt naar de X2 eindstop. Kijk of de printkop stopt zodra deze de eindstop raakt.\r\nSchakel de printer meteen uit als dit niet gebeurt en controlleer de X2 eindstop en kabel."
};

const char DIAG_PAGE7_TITLE[8][30] PROGMEM = {
	"5. Y电机诊断",
	"5. Y motor diagnosis",
 	"5. Yモーター",
	"5. Y motor diagnosis",
    "5. Et diagnostic moteur",
    "5. Diagnose Y-Achsenmotor",
    "5. E diagnosi del motore",
    "5. Y motor diagnose"
};

const char DIAG_PAGE7_LINE[8][100] PROGMEM = {
	"请手动将平台移至中间位置. 然后点击开始.",
	"Please manually move the bed to the middle position.\r\nThen click Start.",
 	"ベッドを中央の位置に手動で移動してください.\r\n次に[開始]をクリックします.",
	"La cama se moverá hacia abajo hasta el tope Z y",
    "Veuillez déplacer manuellement le lit en position médiane.\r\nCliquez ensuite sur Démarrer.",
    "Bitte bewegen Sie das Druckbett per Hand in die Mittelposition und klicken Sie dann auf Start.",
    "Si prega di spostare manualmente il letto nella posizione centrale.\r\nQuindi fare clic su Start.",
    "Verplaats het printbed handmatig naar het midden en druk op Start."
};

const char DIAG_PAGE8_LINE[8][316] PROGMEM = {
	"平台将先向前移动5cm, 再向后移动5cm. 请观察平台移动是否正常.\r\n如有异常, 请关闭打印机, 检查Y电机和连线.",
	"The bed will move forward 5cm first, and then move backward 5cm. Please observe whether the bed movement\r\nis normal.\r\nIf there is any abnormality, please turn off the printer\r\nand check the Y motor and cable.",
 	"作業台は5cm先に進み, 次に5cm後退します.作業台の動きに異常がないか確認してください.\r\n異常がある場合は, プリンターの電源を切り, Yモーターと接続を確認してください.",
	"La cama avanzará 5 cm primero y luego retrocederá 5 cm. Observe si el movimiento de la cama es normal. Si hay alguna anomalía, apague la impresora y compruebe el motor Y y el cable.",
    "Le lit avancera de 5 cm d'abord, puis reculera de 5 cm. Veuillez observer si le mouvement du lit est normal. En cas d'anomalie, veuillez éteindre l'imprimante et vérifier le moteur Y et le cable.",
    "Das Druckbett wird sich um 5cm nach vorne und danach um 5cm nach hinten bewegen. Bitte beobachten Sie, ob die Bewegung normal und flüssig erfolgt.\r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den Y-Achsenmotor und das entsprechende Kabel.",
    "Il letto si muoverà prima in avanti di 5 cm, quindi si muoverà indietro di 5 cm. Si prega di osservare se il movimento del letto è normale. In caso di anomalie, spegnere la stampante e controllare il motore Y e il cavo.",
    "Het printbed zal eerst 5cm naar voren en daarna 5cm naar achteren bewegen. Kijk of het platform normaal beweegt.\r\nSchakel de printer meteen uit als dat niet het geval is en controlleer de Y motor en kabel."
};

const char DIAG_PAGE9_TITLE[8][34] PROGMEM = {
	"6. Y限位开关诊断",
	"6. Y endstop diagnosis",
 	"6. Yエンドストップ",
	"6. Y diagnóstico de tope final",
    "6. Diagnostic de la butée en Y",
    "6. Diagnose Y-Endschalter",
    "6. Diagnosi finecorsa Y",
    "6. Y eindstop diagnose"
};

const char DIAG_PAGE9_LINE[8][278] PROGMEM = {
	"平台将向后移动至Y限位开关处. 请观察平台向后移动至限位开关后是否立即停止.\r\n如有异常, 请关闭打印机, 检查Y限位开关和连线.",
	"The bed will move backward to the Y endstop. Please\r\nobserve whether the bed stops immediately after\r\ntouching the endstop.\r\nIf there is an abnormality, please turn off the printer andcheck the Y endstop and cable.",
 	"作業台がYリミットスイッチまで後退します.リミットスイッチまで後退した直後に作業台が停止するか確認してください.\r\n異常がある場合は, プリンタの電源を切り, Yリミットスイッチと配線を確認してください.",
	"La cama se moverá hacia atrás hasta el tope final en Y. Observe si la cama se detiene inmediatamente después de tocar el tope. Si hay alguna anomalía, apague la impresora y compruebe el cable y el tope final en Y.",
    "Le lit recule jusqu'à la butée Y. Veuillez observer si le lit s'arrête immédiatement après avoir touché la butée. En cas d'anomalie, veuillez éteindre l'imprimante et vérifier la butée en Y et le cable.",
    "Das Druckbett wird sich nach hinten an den Y-Endschalter bewegen. Bitte beobachten Sie, ob das Druckbett sofort bei Berührung des Endschalters stoppt\r\nWenn Sie irgendeine Unregelmabigkeit feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den Y-Endschalter.",
    "Il letto si muoverà all'indietro fino al finecorsa Y. Si prega di osservare se il letto si ferma immediatamente dopo aver toccato il finecorsa. In caso di anomalie, spegnere la stampante e controllare il finecorsa Y e il cavo.",
    "het printbed beweegt naar achteren naa de achterste Y eindstop. Kijk of het printbed meteen stopt zodra deze de eindstop bereikt.\r\nSchakel als dat niet het geval is de printer meteen uit en controlleer de Y eindstop en kabel."
};

const char DIAG_PAGE10_TITLE[8][28] PROGMEM = {
	"7. Z电机诊断",
	"7. Z Motor Diagnosis",
 	"7. Zモーター",
	"7. Con diagnóstico motor",
    "7. Avec diagnostic moteur",
    "7. Diagnose Z-Achsenmotor",
    "7. Mit Motordiagnose",
    "7. Z motor diagnose"
};

const char DIAG_PAGE10_LINE[8][315] PROGMEM = {
	"喷头将先向上移动10cm, 再向下移动5cm. 请观察喷头移动是否正常.\r\n如有异常, 请关闭打印机, 检查Z电机和连线.",
	"The nozzle will first move up 10cm, and then move\r\ndown 5cm. Please observe whether the nozzle moves\r\nnormally.\r\nIf there is any abnormality, please turn off the printer\r\nand check the Z motor and cable.",
 	"プリントヘッドが10cm上昇し, 次に5cm下降しますプリントヘッドが正常に動くか確認してください異常がある場合は, プリンターの電源を切り, Zモーターと配線を確認してください.",
	"La boquilla se moverá primero 10 cm hacia arriba y luego 5 cm hacia abajo. Observe si la boquilla se mueve normalmente. Si hay alguna anomalía, apague la impresora y compruebe el motor Z y el cable.",
    "La buse montera d'abord de 10 cm, puis descendra de 5 cm. Veuillez observer si la buse se déplace normalement. En cas d'anomalie, veuillez éteindre l'imprimante et vérifier le moteur et le cable Z.",
    "Die Düsen werden sich um 10cm nach oben und danach um 5cm nach unten bewegen. Bitte beobachten Sie, ob die Bewegung normal und flüssig erfolgt.\r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den Z-Achsenmotor und das entsprechende Kabel.",
    "L'ugello si muoverà prima verso l'alto di 10 cm, quindi verso il basso di 5 cm. Si prega di osservare se l'ugello si muove normalmente. In caso di anomalie, spegnere la stampante e controllare il motore Z e il cavo.",
    "De printkop beweegt eerst 10cm omhoog en dan 5cm naar beneden. Kijk of de printkop normaal beweegt.\r\nSchakel als dat niet het geval is de printer meteen uit en controlleer de Z motor en kabel."
};

const char DIAG_PAGE11_TITLE[8][32] PROGMEM = {
	"8. 接近开关诊断",
	"8. Proximity diagnostics",
 	"8. 近接スイッチ",
	"8. Diagnóstico de proximidad",
    "8. Diagnostics de proximité",
    "8. Diagnose Annaherungssensor",
    "8. Diagnostica di prossimità",
    "8. Hoogte-sensor diagnose"
};

const char DIAG_PAGE11_LINE[8][280] PROGMEM = {
	"请观察屏幕上接近开关的状态是否为断开状态. 然后找一个铁制工具, 例如金属螺丝刀, 紧贴于接近开关的下方. \r\n观察屏幕上接近开关的状态是否变为导通. 如有异常, 请关闭打印机, 更换接近开关.",
	"Look for an iron tool, such as a metal screwdriver, near the bottom of the proximity.\r\nWatch the status of the proximity changes from off\r\nto on. If abnormal, turn off the printer and replace the\r\nproximity.",
 	"画面上の近接スイッチの状態が切断されていないか確認し, 近接スイッチの下部にある金属製のドライバーなどの鉄製の工具を見つけて, 画面上の近接スイッチの状態が導通するかどうかを確認します. \r\n異常がある場合は, プリンターの電源を切り, 近接スイッチを交換してください.",
	"Busque una herramienta de hierro, como un destornillador de metal, cerca de la parte inferior de la proximidad. Observe el estado de los cambios de proximidad de apagado a encendido. Si es anormal, apague la impresora y reemplace la proximidad.",
    "Recherchez un outil en fer, comme un tournevis en métal, près du bas de la proximité. Regardez l'état des changements de proximité de désactivé à activé. En cas d'anomalie, éteignez l'imprimante et remplacez la proximité.",
    "Nehmen Sie ein metallenes Werkzeug wie z.B. einen Schraubendreher und nahern Sie sich damit dem Annaherungssensor.\r\nBeobachten Sie ob sich der Status des Sensors von AUS zu AN andert.\r\nSollte das nicht geschehen schalten Sie den Drucker aus und ersetzten Sie den Sensor. ",
    "Cerca uno strumento di ferro, come un cacciavite di metallo, vicino al fondo del vicinato. Guarda lo stato della prossimità cambia da spento ad acceso. Se anormale, spegnere la stampante e sostituire la prossimità.",
    "Gebruik een metaal object, bijv. een schroevendraaier en breng deze in de buurt van de onderkant van de hoogte-sensor. \r\nKijk of de status van de hoogte-sensor verandert van Uit\r\nnaar Aan. Schakel de printer uit als dit niet het geval is en vervang de sensor."
};

const char DIAG_PAGE12_TITLE[8][48] PROGMEM = {
	"9. 左挤出器电机诊断",
	"9. Left extruder motor diagnosis",
 	"9. 左の押出機モーター",
	"9. Motor extrusor izquierdo",
    "9. Diagnostic du moteur d'extrudeuse gauche",
    "9. Diagnose linker Extrudermotor",
    "9. Diagnosi motore estrusore sinistro",
    "9. Linker motor diagnose"
};

const char DIAG_PAGE12_LINE[8][360] PROGMEM = {
	"左挤出器电机将顺时针旋转2圈，再逆针旋转2圈. 请观察电机转动是否正常.\r\n如有异常, 请关闭打印机, 检查左挤出器电机和连线.",
	"The left extruder motor will rotate 2 times clockwise, and then 2 times counterwise. Please observe whether the motor rotates normally.\r\nIf anything is abnormal, please turn off the printer and\r\ncheck the left extruder motor and cable.",
 	"左押出機のモーターが時計回りに2回, 反時計回りに2回回転します.モーターが正常に回転するか確認してください.\r\n異常がある場合は, プリンターの電源を切り, 左押出機のモーターと配線を確認してください.",
	"El motor del extrusor izquierdo girará 2 veces en el sentido de las agujas del reloj y luego 2 veces en el sentido contrario. Observe si el motor gira normalmente. Si algo es anormal, apague la impresora y verifique el motor y el cable del extrusor izquierdo.",
    "Le moteur de l'extrudeuse gauche tournera 2 fois dans le sens des aiguilles d'une montre, puis 2 fois dans le sens inverse. Veuillez observer si le moteur tourne normalement. Si quelque chose est anormal, veuillez éteindre l'imprimante et vérifier le moteur et le cable de l'extrudeuse gauche.",
    "Der linke Extrudermotor wird sich 2 mal im Uhrzeigersinn und danach 2 mal gegen den Uhrzeigersinn drehen. Bitte beobachten Sie, ob sich der Motor normal und flüssig bewegt. \r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den Motor des linken Extruders und das entsprechende Kabel.",
    "Il motore dell'estrusore sinistro ruoterà 2 volte in senso orario e poi 2 volte in senso antiorario. Si prega di osservare se il motore gira normalmente. In caso di anomalie, spegnere la stampante e controllare il motore e il cavo dell'estrusore sinistro.",
    "De linker extrusie motor draait 2 maal met de klok mee en 2 maal tegen de klok in. Kijk of de motor normaal beweegt\r\nAls dit niet het geval is, schakel de printer uit en controlleer de linker extrusie motor en kabel."
};

const char DIAG_PAGE13_TITLE[8][43] PROGMEM = {
	"10. 左喷头组件诊断",
	"10. Diagnosis of left nozzle",
 	"10. 左ノズルアセンブリの",
	"10. Diagnóstico de la boquilla izquierda",
    "10. Diagnostic de la buse gauche",
    "10. Diagnose der linken Düse",
    "10. Diagnosi dell'ugello sinistro",
    "10. Linker printkop diagnose"
};

const char DIAG_PAGE13_LINE[8][266] PROGMEM = {
	"左喷头将加热至60度. 请观察屏幕上的温度数值是否快速上升. 如温度数值长时间无变化, 请立即关闭打印机, 更换喷头组件.",
	"The left nozzle will heat up to 60 degrees. Please\r\nobserve whether the temperature value on the screen\r\nrises rapidly.\r\nIf the value does not change for a long time, please\r\nturn off the printer immediately and replace the nozzle.",
 	"左のノズルは60度まで加熱されます.画面の温度値が急激に上昇するかどうかを確認してください.\r\n温度値が長時間変化しない場合は, すぐにプリンタの電源を切り, ノズルアセンブリを交換してください.",
	"La boquilla izquierda se calentará hasta 60 grados. Observe si el valor de temperatura en la pantalla aumenta rápidamente. Si el valor no cambia durante mucho tiempo, apague la impresora inmediatamente y reemplace la boquilla.",
    "La buse gauche chauffera jusqu'à 60 degrés. Veuillez observer si la valeur de température sur l'écran augmente rapidement. Si la valeur ne change pas pendant une longue période, veuillez éteindre l'imprimante immédiatement et remplacer la buse.",
    "Die linke Düse wird sich auf 60 Grad aufheizen. Bitte beobachten Sie, ob sich die Temperaturanzeige am Display entsprechend und zügig andert.\r\nSollte sich der Wert für langere Zeit nicht andern schalten Sie bitte den Drucker sofort aus und ersetzen Sie die Düse",
    "L'ugello sinistro si riscalderà fino a 60 gradi. Si prega di osservare se il valore della temperatura sullo schermo aumenta rapidamente. Se il valore non cambia per molto tempo, spegnere immediatamente la stampante e sostituire l'ugello.",
    "De linker printkop wordt opgewarmd tot 60 graden. Controlleer of de temperatuur op het scherm snel omhoog gaat. Zet de printer uit als de temperatuur niet verandert en vervang dan onmiddellijk de printkop."
};

const char DIAG_PAGE13_LINE2[8][40] PROGMEM = {
	"请检查喷头组件及接口.",
	"Check the nozzle and cable",
 	"ノズルとケーブルを確認する",
	"Compruebe la boquilla y el cable",
    "Vérifiez la buse et le cable",
    "Prüfen Sie Düse und Kabel",
    "Controllare l'ugello e il cavo",
    "Controlleer printkop en kabel"
};

const char DIAG_PAGE14_TITLE[8][53] PROGMEM = {
	"11. 左喷头风扇诊断",
	"11. Diagnosis of left nozzle fan",
 	"11. 左ノズルファンの",
	"11. Diagnóstico del ventilador izquierdo",
    "11. Diagnostic du ventilateur de la buse gauche",
    "11. Diagnose des Bauteillüfters der linken Düse",
    "11. Diagnosi del ventilatore dell'ugello sinistro",
    "11. Linker printkop ventilator diagnose."
};

const char DIAG_PAGE14_LINE[8][256] PROGMEM = {
	"左喷头风扇已开启. 如风扇未转动, 请关闭打印机后更换喷头风扇.",
	"The left nozzle fan is turned on. If the fan does not\r\nrotate, please turn off the printer and replace the fan.",
 	"左側のノズルファンがオンになっています.ファンが回転しない場合は, プリンタの電源を切り, ノズルファンを交換してください.",
	"El ventilador de la boquilla izquierda está encendido. Si el ventilador no gira, apague la impresora y reemplace el ventilador.",
    "La buse gauche chauffera jusqu'à 60 degrés. Veuillez observer si la valeur de température sur l'écran augmente rapidement. Si la valeur ne change pas pendant une longue période, veuillez éteindre l'imprimante immédiatement et remplacer la buse.",
    "Der linke Bauteillüfter wird eingeschaltet. Sollte sich der Lüfter nicht drehen schalten Sie den Drucker ab und ersetzen Sie den Lüfter.",
    "L'ugello sinistro si riscalderà fino a 60 gradi. Si prega di osservare se il valore della temperatura sullo schermo aumenta rapidamente. Se il valore non cambia per molto tempo, spegnere immediatamente la stampante e sostituire l'ugello.",
    "De linker printkop ventilator staat aan. Als de ventilator niet draait, zet de printer uit en vervang de ventilator."
};

const char DIAG_PAGE15_TITLE[8][48] PROGMEM = {
	"12. 右挤出器电机诊断",
	"12. Right extruder motor diagnosis",
 	"12. 正しい押出機モーター",
	"12. Motor extrusor izquierdo",
    "12. Diagnostic du moteur d'extrudeuse droit",
    "12. Diagnose rechter Extrudermotor",
    "12. Diagnosi motore estrusore destro",
    "12. Rechter extrusie motor diagnose"
};

const char DIAG_PAGE15_LINE[8][360] PROGMEM = {
	"右挤出器电机将顺时针旋转2圈，再逆针旋转2圈. 请观察电机转动是否正常.\r\n如有异常, 请关闭打印机, 检查右挤出器电机和连线.",
	"The right extruder motor will rotate 2 times clockwise,\r\nand then 2 times counterwise. Please observe whether\r\nthe motor rotates normally. If there is any abnormality,\r\nplease turn off the printer and check the right extruder motor and cable.",
 	"右のエクストルーダーモーターが時計回りに2回, 反時計回りに2回転します.モーターが正常に回転するか確認してください.\r\n異常がある場合は, プリンターの電源を切り, エクストルーダーのモーターと配線を確認してください.",
	"El motor de la extrusora derecho girará 2 veces en el sentido de las agujas del reloj y luego 2 veces en el sentido contrario. Observe si el motor gira normalmente. Si hay alguna anomalía, apague la impresora y compruebe el motor y el cable de la extrusora correctos.",
    "Le moteur droit de l'extrudeuse tournera 2 fois dans le sens des aiguilles d'une montre, puis 2 fois dans le sens inverse. Veuillez observer si le moteur tourne normalement. S'il y a une anomalie, veuillez éteindre l'imprimante et vérifier le moteur et le cable de l'extrudeuse appropriés.",
    "Der rechte Extrudermotor wird sich 2 mal im Uhrzeigersinn und danach 2 mal gegen den Uhrzeigersinn drehen. Bitte beobachten Sie, ob sich der Motor normal und ruckfrei bewegt. \r\nWenn Sie irgendeine Unregelmabigkeit bei der Bewegung feststellen, schalten Sie den Drucker sofort ab und prüfen Sie den Motor des rechten Extruders und das entsprechende Kabel.",
    "Il motore dell'estrusore destro ruoterà 2 volte in senso orario e poi 2 volte in senso antiorario. Si prega di osservare se il motore gira normalmente. In caso di anomalie, spegnere la stampante e controllare il motore e il cavo dell'estrusore corretti.",
    "De rechter extrusie motor draait 2 maal met de klok mee en 2 maal tegen de klok in. Kijk of de motor normaal beweegt\r\nAls dit niet het geval is, schakel de printer uit en controlleer de rechter extrusie motor en kabel."
};

const char DIAG_PAGE16_TITLE[8][40] PROGMEM = {
	"13. 右喷头组件诊断",
	"13. Diagnosis of right nozzle",
 	"13. 正しいノズルアセンブリの",
	"13. Diagnóstico de boquilla derecha",
    "13. Diagnostic de la buse droite",
    "13. Diagnose der rechten Düse",
    "13. Diagnosi dell'ugello destro",
    "13. Rechter printkop diagnose"
};

const char DIAG_PAGE16_LINE[8][266] PROGMEM = {
	"右喷头将加热至60度. 请观察屏幕上的温度数值是否快速上升. 如温度数值长时间无变化, 请立即关闭打印机, 更换喷头组件.",
	"The right nozzle will heat to 60 degrees. Please observe whether the temperature value on the screen rises rapidly. If the value does not change for a long time, please  turn off the printer immediately and replace the nozzle.",
 	"右側のノズルが60度に加熱されます.画面の温度値が急激に上昇するかどうかを確認してください.温度値が長時間変化しない場合は, すぐにプリンタの電源を切り, ノズルアセンブリを交換してください.",
	"La boquilla derecha se calentará a 60 grados. Observe si el valor de temperatura en la pantalla aumenta rápidamente. Si el valor no cambia durante mucho tiempo, apague la impresora inmediatamente y reemplace la boquilla.",
    "La buse droite chauffera à 60 degrés. Veuillez observer si la valeur de température sur l'écran augmente rapidement. Si la valeur ne change pas pendant une longue période, veuillez éteindre l'imprimante immédiatement et remplacer la buse.",
    "Die rechte Düse wird sich auf 60 Grad aufheizen. Bitte beobachten Sie, ob sich die Temperaturanzeige am Display entsprechend zügig andert.\r\nSollte sich der Wert für langere Zeit nicht andern schalten Sie bitte den Drucker sofort aus und ersetzen Sie die Düse",
    "L'ugello giusto si riscalderà a 60 gradi. Si prega di osservare se il valore della temperatura sullo schermo aumenta rapidamente. Se il valore non cambia per molto tempo, spegnere immediatamente la stampante e sostituire l'ugello.",
    "De rechter printkop wordt opgewarmd tot 60 graden. Controlleer of de temperatuur op het scherm snel omhoog gaat. Zet de printer uit als de temperatuur niet verandert en vervang dan onmiddellijk de printkop."
};

const char DIAG_PAGE17_TITLE[8][55] PROGMEM = {
	"14. 右喷头风扇诊断",
	"14. Diagnosis of right nozzle fan",
 	"14. 右ノズルファンの",
	"14. Diagnóstico del ventilador derecho",
    "14. Diagnostic du ventilateur de la buse droite",
    "14. Diagnose des Bauteillüfters der rechten Düse",
    "14. Diagnosi del ventilatore dell'ugello destro",
    "14. Rechter printkop ventilator diagnose"
};

const char DIAG_PAGE17_LINE[8][148] PROGMEM = {
	"右喷头风扇已开启. 如风扇未转动, 请关闭打印机后更换喷头风扇.",
	"The right nozzle fan is turned on. If the fan does not\r\nrotate, please turn off the printer and replace the fan.",
 	"右側のノズルファンがオンになっています.ファンが回転しない場合は, プリンタの電源を切り, ノズルファンを交換してください.",
	"El ventilador de la boquilla derecha está encendido. Si el ventilador no gira, apague la impresora y reemplace el ventilador.",
    "Le ventilateur de buse droit est allumé. Si le ventilateur ne tourne pas, veuillez éteindre l'imprimante et remplacer le ventilateur.",
    "Der rechte Bauteillüfter wird eingeschaltet. Sollte sich der Lüfter nicht drehen schalten Sie den Drucker ab und ersetzen Sie den Lüfter.",
    "La ventola dell'ugello destro è attivata. Se la ventola non gira, spegnere la stampante e sostituire la ventola.",
    "De rechter printkop ventilator staat aan. Als de ventilator niet draait, zet de printer uit en vervang de ventilator."
};

const char DIAG_PAGE18_TITLE[8][40] PROGMEM = {
	"15. 平台加热诊断",
	"15. Heated bed diagnosis",
 	"15. 加熱ベッドの",
	"15. Diagnóstico de cama climatizada",
    "15. Diagnostic du lit chauffant",
    "15. Diagnose des Heizbettes",
    "15. Diagnosi letto riscaldato",
    "15. Verwarmd bed diagnose"
};

const char DIAG_PAGE18_LINE[8][278] PROGMEM = {
	"平台将加热至40度.  请观察屏幕上的温度数值是否快速上升. 如温度数值长时间无变化, 请立即关闭打印机, 检查加热平台和连线.",
	"The bed will heat up to 40 degrees. Please observe\r\nwhether the temperature value on the screen rises\r\nrapidly. If the value does not change for a long time,\r\nplease turn off the printer immediately and check the\r\nheated bed and cable.",
 	"プラットフォームは40度まで加熱します.画面の温度値が急激に上昇するかどうかを確認してください.温度値が長時間変化しない場合は, すぐにプリンタの電源を切り, 加熱プラットフォームと配線を確認してください.",
	"La cama se calentará hasta 40 grados. Observe si el valor de temperatura en la pantalla aumenta rápidamente. Si el valor no cambia durante mucho tiempo, apague la impresora inmediatamente y compruebe la cama y el cable calefactados.",
    "The bed will heat up to 40 degrees. Please observe whether the temperature value on the screen rises rapidly. If the value does not change for a long time, please turn off the printer immediately and check the heated bed and cable.",
    "Das Druckbett wird sich auf 40 Grad aufheizen. Bitte beobachten Sie, ob sich die Temperaturanzeige am Display entsprechend zügig andert.\r\nSollte sich der Wert für langere Zeit nicht andern schalten Sie bitte den Drucker sofort aus und prüfen Sie das Heizbett und Kabel.",
    "Il letto si riscalderà fino a 40 gradi. Si prega di osservare se il valore della temperatura sullo schermo aumenta rapidamente. Se il valore non cambia per molto tempo, spegnere immediatamente la stampante e controllare il piano riscaldato e il cavo.",
    "Het bed warmt op tot 40 graden. Kijk of de temperatuur op het scherm snel verandert. Als de waarde lang hetzelfde blijft, zet dan onmiddellijk de printer uit en controlleer verwarmd bed en kabel."
};

const char DIAG_PAGE18_LINE2[8][50] PROGMEM = {
	"请检查加热平台及连线.",
	"Check the heated bed and cable.",
 	"加熱プラットフォームと接続を確認してください.",
	"Verifique la cama y el cable con calefacción",
    "Check the heated bed and cable.",
    "Prüfen Sie das Heizbett und Kabel.",
    "Controllare il letto riscaldato e il cavo.",
    "Controlleer verwarmd bed en kabel"
};

#endif // 
