#include "KontrahenciLista.moc"
#include <Qt/qdom.h>
#include <qdir.h>
#include <qmessagebox.h>
#include <QTextStream>

QStringList listaFirmy;

QStringList listaUrzedy;

void KontrahenciLista::init ()
{
  QDir tmp;
  QString progDir = tmp.homePath () + "/elinux";
  listaFirmy.clear ();
  listaUrzedy.clear ();
  readKontr (progDir);
  listBox1->clear ();
  listBox1->addItems ( (QStringList &)listaFirmy);
}

void KontrahenciLista::readKontr (QString progDir)
{
  QDomDocument doc ("kontrahenci");
  QDomElement root;
  QDomElement urzad;
  QDomElement firma;

  QFile file (progDir + "/kontrah.xml");
  if (!file.open (QIODevice::ReadOnly))
    {
      qDebug ("file doesn't exists");
      return;

    }
  else
    {
      QTextStream stream (&file);
      if (!doc.setContent (stream.readAll ()))
	{
	  qDebug ("can not set content ");
	  file.close ();
	  return;
	}
      else
	{
	  root = doc.documentElement ();
	  urzad = root.firstChild ().toElement ();
	  firma = root.lastChild ().toElement ();
	}
      QString text;

      for (QDomNode n = firma.firstChild (); !n.isNull ();
	   n = n.nextSibling ())
	{

	  text =  n.toElement ().attribute ("name");
	  text +=  ", " + n.toElement ().attribute ("code");
	  text +=  " " + n.toElement ().attribute ("place");
	  text +=  ", ul. " + n.toElement ().attribute ("address");
	  text +=  ", NIP: " + n.toElement ().attribute ("nip");
	  listaFirmy.append ( text );
	}

      for (QDomNode n = urzad.firstChild (); !n.isNull ();
	   n = n.nextSibling ())
	{

	  text = n.toElement ().attribute ("name") ;
	  text += ", " + n.toElement ().attribute ("code") ;
	  text += " " + n.toElement ().attribute ("place") ;
	  text += ", ul. " + n.toElement ().attribute ("address") ;
	  text += ", NIP: " + n.toElement ().attribute ("nip") ;
	  listaUrzedy.append (text);
	}
    }
}


void KontrahenciLista::doAccept ()
{
    QList<QListWidgetItem *> selected = listBox1->selectedItems();
  if (!selected.isEmpty())
    {
      ret = selected[0]->text();
      accept ();
    }
  else
    {
      QMessageBox::information (this, "QFaktury", "Wska� kontrahenta.",
				QMessageBox::Ok);
    }
}

void KontrahenciLista::comboBox1Changed ()
{
  qDebug (__FUNCTION__);
  listBox1->clear ();
  switch (comboBox1->currentIndex ())
    {
    case 0:
      listBox1->addItems ((QStringList &)listaFirmy);
      break;
    case 1:
      listBox1->addItems ((QStringList &)listaUrzedy);
      break;
    }
}
KontrahenciLista::KontrahenciLista(QWidget *parent): QDialog(parent) {
    setupUi(this);
    init();
}
