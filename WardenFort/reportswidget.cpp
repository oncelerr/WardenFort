#include "reportswidget.h"
#include "ui_reportswidget.h"
#include <QMouseEvent>
#include <QDebug>

reportsWidget::reportsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reportsWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &reportsWidget::print);
}

reportsWidget::~reportsWidget()
{
    delete ui;
}

void reportsWidget::setDate(const QString &date) {
    ui->dateLabel->setText(date);
    ui->dateLabel->setVisible(!date.isEmpty()); // Hide the date label if empty
}

void reportsWidget::setID(const QString &id) {
    ui->idLabel->setText(id);
}

void reportsWidget::createPDFWithTemplate(const QString &fileName, const QString &filePath, const QString &reportedDate) {
    // Define your printable template using HTML and CSS
    QString htmlTemplate = R"(
<html>
    <head>
        <style>
            .form-table {
                width: 100%;
                border-collapse: collapse;
                margin-top: 20px;
                box-sizing: border-box;
                text-align: center;
            }
            .form-table th, .form-table td {
                border: 1px solid #000;
                padding: 10px;
                text-align: left;
                box-sizing: border-box;
            }
            .form-table tr{
                text-align: center;
            }
            .signature {
                margin-top: 40px;
                text-align: center;
            }
        </style>
    </head>
    <body>
        <div class="header"></div>

        <table class="form-table">
            <tr>
                <td style="border: 0px; font-weight:  bold;">Reported By: </td>
                <td style="border: 0px; font-weight: bold;">Date of Report: %1</td>

            </tr>
            <tr>
                <td style="border: 0px; font-weight:  bold;">Reported to:</td>
                <td style="border: 0px;"></td>
            </tr>
        </table>

        <table class="form-table">
            <tr>
                <th colspan="2">Incident Details</th>
            </tr>
            <tr>
                <td>
                    <label for="date-time-incident">Date and Time of Incident:</label>
                </td>
                <td>
                    <label for="location">Location:</label>
                </td>
            </tr>
            <tr>
                <th colspan="2">Incident Overview</th>
            </tr>
            <tr>
                <td>
                    <label for="incident-type">Incident Type(s):</label>
                </td>
                <td>
                    <label for="incident-type-text">%2</label>
                </td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center; font-weight: bold; border: 1px solid #000;">
                    <label for="description-incident">Description of Incident</label>
                </td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center; font-weight: bold; height: 50px;"></td>
            </tr>
            <tr>
                <td style="border: 0px; font-weight:  bold;"></td>
            </tr>
            <tr>
                <td>
                    <label for="impact-assessment" style="font-weight: bold; text-align: center;">Impact Assessment:</label>
                </td>
                <td>
                    <label for="root-cause-analysis" style="font-weight: bold; text-align: center;">Root Cause Analysis:</label>
                </td>
            </tr>
            <tr>
                <td>
                    <label for="impact-assessment"></label>
                </td>
                <td>
                    <label for="root-cause-analysis"></label>
                </td>
            </tr>
        </table>

        <div class="signature">
            _______________________________________<br>
            Name with printed signature
        </div>
    </body>
    </html>
    )";
    QString htmlContent = htmlTemplate.arg(reportedDate).arg(incidentTypes);
    // Create a QTextDocument and set the HTML content
    QTextDocument document;
    document.setHtml(htmlContent); // Use htmlContent instead of htmlTemplate


    // Create a printer and set properties
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath + "/" + fileName + ".pdf"); // Set the output file path and name
    printer.setPageSize(QPageSize::Letter);

    // Create a painter
    QPainter painter(&printer);
    painter.begin(&printer);

    // Calculate the position and size of the image
    QImage image("C:/Users/admin/Downloads/unnamed.png");
    if (!image.isNull()) {
        // Resize image if needed (convert inches to pixels based on printer resolution)
        double dpiX = printer.resolution(); // DPI of the printer
        double dpiY = printer.resolution();
        int paperWidth = printer.pageRect(QPrinter::DevicePixel).width();
        int paperHeight = printer.pageRect(QPrinter::DevicePixel).height();
        int imgWidth = paperWidth; // Full width of the paper
        int imgHeight = (imgWidth * image.height()) / image.width(); // Maintain aspect ratio

        int xOffset = (paperWidth - imgWidth) / 2;
        QRect imageRect(xOffset, 0, imgWidth, imgHeight);
        painter.drawImage(imageRect, image);
        painter.translate(0, imgHeight); // Move the origin down by the height of the image
    }

    // Set document width to the width of the printer page
    document.setPageSize(QSizeF(printer.pageRect(QPrinter::DevicePixel).size()));

    // Render the QTextDocument to the painter
    document.drawContents(&painter, QRectF(0, 0, printer.pageRect(QPrinter::DevicePixel).width(), printer.pageRect(QPrinter::DevicePixel).height()));

    // Cleanup
    painter.end();
}

void reportsWidget::print() {
    // Get the filename and destination file location from the user
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");
    QString filePath = QFileInfo(fileName).path(); // Extract the directory path

    if (!fileName.isEmpty()) {
        // Get the reported date from the dateLabel
        QString reportedDate = ui->dateLabel->text();

        // Create the PDF with the template
        createPDFWithTemplate(QFileInfo(fileName).baseName(), filePath, reportedDate);
    }
}
void reportsWidget::setIncidentTypes(const QString &types) {
   incidentTypes = types;
    qDebug() << incidentTypes;
}
