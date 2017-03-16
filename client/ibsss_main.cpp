#include "ibsss_client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication * application = new QApplication(argc, argv);
    IBSSS_Client client;
    client.init(application);
    return client.run();
}
