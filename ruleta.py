import serial
import gtk

try:
	ser=serial.Serial('/dev/ttyACM1', 9600)
except:
	ser=serial.Serial('/dev/ttyACM0', 9600)
python='e'
tiempo=500
clicks=0

def parar(widget):
	global clicks
	clicks = clicks+1
	ser.write('a')
	etiqueta.set_text("Clica el boton cuando se ilumine el led central.  Numero de clicks: "+str(clicks))

def reiniciar(widget):
	global clicks
	clicks=0
	ser.write('r')
	etiqueta.set_text("Clica el boton cuando se ilumine el led central.  Numero de clicks: 0")


ventana = gtk.Window()
ventana.set_default_size (300,300)
ventana.connect("destroy",gtk.main_quit)
tabla = gtk.Table (2,2, homogeneous=True)
	

boton = gtk.Button("Parar")
boton.connect("clicked",parar)
tabla.attach(boton,0,1,1,2)

boton_reiniciar = gtk.Button("Reiniciar")
boton_reiniciar.connect("clicked",reiniciar)
tabla.attach(boton_reiniciar,1,2,1,2)
	
etiqueta=gtk.Label("Clica el boton cuando se ilumine el led central.  Numero de clicks: 0")
tabla.attach(etiqueta,0,2,0,1)

	
ventana.add(tabla)
boton.show()
ventana.set_default_size(500,75)
ventana.set_position(gtk.WIN_POS_CENTER_ALWAYS)
ventana.set_title("Ruleta")
ventana.show_all()
	


	
	


gtk.main()
